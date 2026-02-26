// =============================================================================
// Exercise 6: XOR Network (Capstone!)
// =============================================================================
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
// YOUR TASK:
//   1. Implement forwardPass() — compute hidden layer then output
//   2. Implement backprop() — compute gradients for ALL weights
//   3. Implement updateWeights() — apply gradient descent
//   4. Train until XOR is solved!
//
// This is the hardest exercise. Take your time.
// =============================================================================

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoidDeriv(double output) {
    // Takes the ALREADY-COMPUTED sigmoid output, not raw z
    return output * (1.0 - output);
}

struct XORNetwork {
    // Hidden layer (2 neurons, 2 inputs each)
    double wh[2][2];   // wh[neuron][input]
    double bh[2];      // bias for each hidden neuron

    // Output layer (1 neuron, 2 inputs from hidden)
    double wo[2];      // weights from hidden to output
    double bo;         // bias for output

    // Stored activations (needed for backprop)
    double h[2];       // hidden layer outputs
    double o;          // final output

    double learning_rate;
};

// Initialize weights with small random values
void initNetwork(XORNetwork& net) {
    srand(42);  // fixed seed for reproducibility
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            net.wh[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;  // [-1, 1]
        }
        net.bh[i] = ((double)rand() / RAND_MAX) * 2 - 1;
        net.wo[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    net.bo = ((double)rand() / RAND_MAX) * 2 - 1;
    net.learning_rate = 2.0;
}

// TODO: Implement the forward pass
// Store intermediate values in net.h[] and net.o for use in backprop
double forwardPass(XORNetwork& net, double x1, double x2) {
    // YOUR CODE HERE

    // Step 1: Compute hidden neuron 0
    // net.h[0] = sigmoid(wh[0][0]*x1 + wh[0][1]*x2 + bh[0])

    // Step 2: Compute hidden neuron 1
    // net.h[1] = sigmoid(wh[1][0]*x1 + wh[1][1]*x2 + bh[1])

    // Step 3: Compute output
    // net.o = sigmoid(wo[0]*h[0] + wo[1]*h[1] + bo)

    return net.o;
}

// TODO: Implement backpropagation for the entire network
// This is where it gets interesting — you need to propagate gradients
// backward through the hidden layer.
//
// The chain rule for a 2-layer network:
//
// OUTPUT LAYER:
//   error_o      = predicted - target
//   delta_o      = error_o * sigmoidDeriv(predicted)
//   grad_wo[i]   = delta_o * h[i]
//   grad_bo      = delta_o
//
// HIDDEN LAYER (this is the "back" propagation part!):
//   error_h[i]   = delta_o * wo[i]        <-- error flows BACK through wo
//   delta_h[i]   = error_h[i] * sigmoidDeriv(h[i])
//   grad_wh[i][j]= delta_h[i] * input[j]
//   grad_bh[i]   = delta_h[i]
//
void backprop(XORNetwork& net, double x1, double x2, double target) {
    // YOUR CODE HERE

    // --- Output layer gradients ---
    // double error_o = ???
    // double delta_o = ???

    // --- Hidden layer gradients ---
    // For each hidden neuron i:
    //   double error_h = delta_o * net.wo[i]
    //   double delta_h = error_h * sigmoidDeriv(net.h[i])

    // --- Update all weights ---
    // Output weights: wo[i] -= lr * delta_o * h[i]
    // Output bias:    bo    -= lr * delta_o
    // Hidden weights: wh[i][0] -= lr * delta_h * x1
    //                 wh[i][1] -= lr * delta_h * x2
    // Hidden bias:    bh[i]    -= lr * delta_h
}

int main() {
    XORNetwork net;
    initNetwork(net);

    // XOR training data
    double inputs[][2] = {{0,0}, {0,1}, {1,0}, {1,1}};
    double targets[]   = { 0,     1,     1,     0   };
    int n_samples = 4;

    int epochs = 20000;

    cout << "=== Training XOR Network ===" << endl;
    cout << "Architecture: 2 -> 2 -> 1" << endl;
    cout << "Learning rate: " << net.learning_rate << endl << endl;

    for (int epoch = 0; epoch < epochs; epoch++) {
        double total_loss = 0.0;

        for (int i = 0; i < n_samples; i++) {
            // Forward
            double predicted = forwardPass(net, inputs[i][0], inputs[i][1]);

            // Loss
            double error = targets[i] - predicted;
            total_loss += error * error;

            // Backward + Update
            backprop(net, inputs[i][0], inputs[i][1], targets[i]);
        }

        if (epoch % 2000 == 0) {
            cout << "Epoch " << epoch << " | Loss: " << total_loss / n_samples << endl;
        }
    }

    // Test
    cout << "\n=== XOR Results ===" << endl;
    bool all_correct = true;
    for (int i = 0; i < n_samples; i++) {
        double output = forwardPass(net, inputs[i][0], inputs[i][1]);
        bool correct = ((output > 0.5) == (targets[i] > 0.5));
        if (!correct) all_correct = false;
        cout << "(" << inputs[i][0] << ", " << inputs[i][1]
             << ") -> " << output
             << " (expected: " << targets[i] << ")"
             << (correct ? " OK" : " WRONG")
             << endl;
    }

    cout << "\n" << (all_correct ? "SUCCESS! XOR learned!" : "Not yet... try adjusting learning rate or epochs") << endl;

    // TIPS IF IT'S NOT CONVERGING:
    // - Try learning_rate = 2.0 or 5.0 (XOR needs aggressive learning)
    // - Try more epochs (50000+)
    // - Try different random seeds in initNetwork()
    // - Make sure you're updating ALL weights (hidden + output)

    return 0;
}
