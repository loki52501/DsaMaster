// =============================================================================
// Exercise 8: XOR Network (Capstone)
// =============================================================================
//
// The XOR problem CANNOT be solved by a single neuron because it's not
// linearly separable. You need a hidden layer!
//
//   (0,0) -> 0
//   (0,1) -> 1
//   (1,0) -> 1
//   (1,1) -> 0
//
// Network: 2 inputs -> 2 hidden neurons -> 1 output neuron
//
// This exercise brings together EVERYTHING from exercises 1-7:
//   - Tensors and matrix operations
//   - Activation functions (sigmoid)
//   - Loss functions (MSE)
//   - Gradients and backpropagation
//   - SGD with weight updates
//   - Training loop with DataLoader
//   - Zeroing gradients
//   - Validation metrics
//
// YOUR TASK:
//   1. Implement forwardPass() — compute hidden layer then output
//   2. Implement backprop() — compute gradients for ALL weights
//   3. Train until XOR is solved!
//
// =============================================================================

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

double sigmoid(double x) { return 1.0 / (1.0 + exp(-x)); }

struct XORNetwork {
    // Hidden layer (2 neurons, 2 inputs each)
    double wh[2][2];   // wh[neuron][input]
    double bh[2];

    // Output layer (1 neuron, 2 inputs from hidden)
    double wo[2];
    double bo;

    // Stored activations (needed for backprop)
    double h[2];       // hidden layer outputs
    double o;          // final output

    // Gradients
    double grad_wh[2][2];
    double grad_bh[2];
    double grad_wo[2];
    double grad_bo;

    double learning_rate;
};

void initNetwork(XORNetwork& net) {
    srand(42);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            net.wh[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
            net.grad_wh[i][j] = 0;
        }
        net.bh[i] = ((double)rand() / RAND_MAX) * 2 - 1;
        net.wo[i] = ((double)rand() / RAND_MAX) * 2 - 1;
        net.grad_bh[i] = 0;
        net.grad_wo[i] = 0;
    }
    net.bo = ((double)rand() / RAND_MAX) * 2 - 1;
    net.grad_bo = 0;
    net.learning_rate = 2.0;
}

void zeroGrad(XORNetwork& net) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) net.grad_wh[i][j] = 0;
        net.grad_bh[i] = 0;
        net.grad_wo[i] = 0;
    }
    net.grad_bo = 0;
}

// TODO: Implement the forward pass
// Store intermediate values in net.h[] and net.o for use in backprop
double forwardPass(XORNetwork& net, double x1, double x2) {
    // YOUR CODE HERE

    // Hidden neuron 0: net.h[0] = sigmoid(wh[0][0]*x1 + wh[0][1]*x2 + bh[0])
    // Hidden neuron 1: net.h[1] = sigmoid(wh[1][0]*x1 + wh[1][1]*x2 + bh[1])
    // Output:          net.o    = sigmoid(wo[0]*h[0] + wo[1]*h[1] + bo)

    return net.o;
}

// TODO: Implement backpropagation
// Accumulate gradients (don't update weights here!)
void backward(XORNetwork& net, double x1, double x2, double target) {
    // YOUR CODE HERE

    // Output layer:
    //   error_o  = net.o - target
    //   delta_o  = error_o * net.o * (1 - net.o)    [sigmoid deriv on output]
    //   grad_wo[i] += delta_o * net.h[i]
    //   grad_bo    += delta_o

    // Hidden layer (propagate error BACKWARD through wo):
    //   For each hidden neuron i:
    //     error_h  = delta_o * net.wo[i]
    //     delta_h  = error_h * net.h[i] * (1 - net.h[i])
    //     grad_wh[i][0] += delta_h * x1
    //     grad_wh[i][1] += delta_h * x2
    //     grad_bh[i]    += delta_h
}

// Apply accumulated gradients
void step(XORNetwork& net) {
    for (int i = 0; i < 2; i++) {
        net.wo[i] -= net.learning_rate * net.grad_wo[i];
        net.bh[i] -= net.learning_rate * net.grad_bh[i];
        for (int j = 0; j < 2; j++) {
            net.wh[i][j] -= net.learning_rate * net.grad_wh[i][j];
        }
    }
    net.bo -= net.learning_rate * net.grad_bo;
}

// =============================================================================

int main() {
    XORNetwork net;
    initNetwork(net);

    // XOR data — split into "training" and "validation" (same here, for demo)
    struct Sample { double x1, x2, target; };
    vector<Sample> train_data = {{0,0,0}, {0,1,1}, {1,0,1}, {1,1,0}};
    vector<Sample> valid_data = {{0,0,0}, {0,1,1}, {1,0,1}, {1,1,0}};

    int epochs = 20000;
    int batch_size = 2;  // mini-batch training!

    cout << "=== Training XOR Network ===" << endl;
    cout << "Architecture: 2 -> 2 -> 1" << endl;
    cout << "Batch size: " << batch_size << endl;
    cout << "Learning rate: " << net.learning_rate << endl << endl;

    for (int epoch = 0; epoch < epochs; epoch++) {
        // Shuffle training data each epoch
        random_shuffle(train_data.begin(), train_data.end());

        double train_loss = 0.0;

        // Process mini-batches
        for (int b = 0; b < (int)train_data.size(); b += batch_size) {
            zeroGrad(net);  // Zero gradients before each batch!

            int end = min(b + batch_size, (int)train_data.size());
            for (int i = b; i < end; i++) {
                double pred = forwardPass(net, train_data[i].x1, train_data[i].x2);
                double err = train_data[i].target - pred;
                train_loss += err * err;
                backward(net, train_data[i].x1, train_data[i].x2, train_data[i].target);
            }

            step(net);  // Update weights after each batch
        }

        // Validation every 2000 epochs
        if (epoch % 2000 == 0) {
            int correct = 0;
            double val_loss = 0;
            for (auto& s : valid_data) {
                double pred = forwardPass(net, s.x1, s.x2);
                double err = s.target - pred;
                val_loss += err * err;
                if ((pred > 0.5) == (s.target > 0.5)) correct++;
            }
            printf("Epoch %5d | Train loss: %.4f | Val loss: %.4f | Val acc: %d/4\n",
                   epoch, train_loss / 4, val_loss / 4, correct);
        }
    }

    // Final test
    cout << "\n=== XOR Results ===" << endl;
    bool all_correct = true;
    for (auto& s : valid_data) {
        double pred = forwardPass(net, s.x1, s.x2);
        bool correct = (pred > 0.5) == (s.target > 0.5);
        if (!correct) all_correct = false;
        printf("  (%.0f, %.0f) -> %.4f (expected: %.0f) %s\n",
               s.x1, s.x2, pred, s.target, correct ? "OK" : "WRONG");
    }
    cout << "\n" << (all_correct ? "XOR SOLVED!" : "Not converged yet — try more epochs or different lr") << endl;

    return 0;
}
