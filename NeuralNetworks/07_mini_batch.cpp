// =============================================================================
// Exercise 7: Mini-Batch Training
// =============================================================================
// In real training, we don't always use the full dataset at once.
// There are three strategies:
//
//   1. Batch Gradient Descent:      Use ALL samples, then update once
//   2. Stochastic Gradient Descent: Use 1 sample, update immediately (ex 5 & 6)
//   3. Mini-Batch Gradient Descent: Use a small batch, then update
//
// Mini-batch is the standard in practice — it balances speed and stability.
//
// YOUR TASK:
//   1. Implement accumulateGradients() — sum gradients over a batch
//   2. Implement applyBatchUpdate() — average and apply the accumulated gradients
//   3. Compare convergence of batch_size=1 vs batch_size=4
// =============================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

double sigmoid(double x) { return 1.0 / (1.0 + exp(-x)); }
double sigmoidDeriv(double out) { return out * (1.0 - out); }

struct Sample {
    double x1, x2;
    double target;
};

struct SingleNeuron {
    double w1, w2, bias;
    double learning_rate;

    // Accumulated gradients for batch training
    double acc_gw1, acc_gw2, acc_gbias;
    int acc_count;

    void init() {
        w1 = 0.5; w2 = 0.5; bias = -0.2;
        learning_rate = 1.0;
        resetAccumulators();
    }

    void resetAccumulators() {
        acc_gw1 = 0; acc_gw2 = 0; acc_gbias = 0; acc_count = 0;
    }

    double forward(double x1, double x2) {
        return sigmoid(w1 * x1 + w2 * x2 + bias);
    }
};

// TODO: Compute gradients for one sample and ACCUMULATE them (don't apply yet)
// This is different from exercise 5 where we updated immediately.
// Here we sum up gradients across multiple samples before updating.
void accumulateGradients(SingleNeuron& n, double x1, double x2, double target) {
    double predicted = n.forward(x1, x2);

    // YOUR CODE HERE
    // 1. Compute gradients (same as exercise 5)
    // double dLoss_dPred = 2.0 * (predicted - target);
    // double dPred_dZ = sigmoidDeriv(predicted);
    // double delta = dLoss_dPred * dPred_dZ;

    // 2. ADD to accumulators (don't overwrite!)
    // n.acc_gw1 += delta * x1;
    // n.acc_gw2 += delta * x2;
    // n.acc_gbias += delta;
    // n.acc_count++;
}

// TODO: Apply the averaged accumulated gradients, then reset
void applyBatchUpdate(SingleNeuron& n) {
    if (n.acc_count == 0) return;

    // YOUR CODE HERE
    // 1. Average the gradients: divide by acc_count
    // 2. Update weights: w -= learning_rate * avg_gradient
    // 3. Reset accumulators

    n.resetAccumulators();
}

// Train with a given batch size and return loss history
vector<double> train(int batch_size, int epochs) {
    SingleNeuron neuron;
    neuron.init();

    // AND gate data
    vector<Sample> data = {{0,0,0}, {0,1,0}, {1,0,0}, {1,1,1}};

    vector<double> loss_history;

    for (int epoch = 0; epoch < epochs; epoch++) {
        double total_loss = 0.0;
        int samples_in_batch = 0;

        for (int i = 0; i < (int)data.size(); i++) {
            // Accumulate gradient for this sample
            double pred = neuron.forward(data[i].x1, data[i].x2);
            total_loss += (pred - data[i].target) * (pred - data[i].target);

            accumulateGradients(neuron, data[i].x1, data[i].x2, data[i].target);
            samples_in_batch++;

            // Apply update when batch is full
            if (samples_in_batch == batch_size) {
                applyBatchUpdate(neuron);
                samples_in_batch = 0;
            }
        }

        // Apply remaining gradients if dataset isn't divisible by batch_size
        if (samples_in_batch > 0) {
            applyBatchUpdate(neuron);
        }

        loss_history.push_back(total_loss / data.size());
    }

    return loss_history;
}

int main() {
    int epochs = 5000;

    cout << "=== Mini-Batch Training Comparison ===" << endl;
    cout << "Task: AND gate | Epochs: " << epochs << endl << endl;

    // Train with different batch sizes
    vector<double> loss_sgd   = train(1, epochs);  // SGD (batch=1)
    vector<double> loss_mini  = train(2, epochs);   // Mini-batch (batch=2)
    vector<double> loss_batch = train(4, epochs);   // Full batch (batch=4)

    // Print comparison at key epochs
    cout << "Epoch\t| SGD(b=1)\t| Mini(b=2)\t| Batch(b=4)" << endl;
    cout << "--------+-----------+-----------+-----------" << endl;

    vector<int> checkpoints = {0, 100, 500, 1000, 2000, 4999};
    for (int ep : checkpoints) {
        printf("%d\t| %.6f\t| %.6f\t| %.6f\n",
               ep, loss_sgd[ep], loss_mini[ep], loss_batch[ep]);
    }

    cout << "\n=== Observations ===" << endl;
    cout << "- SGD (batch=1): Updates after every sample. Noisy but fast early progress." << endl;
    cout << "- Mini-batch (batch=2): Smoother updates. Good balance." << endl;
    cout << "- Full batch (batch=4): Smoothest but can be slower to converge." << endl;
    cout << "\nIn practice, mini-batch (32-256 samples) is the standard choice." << endl;

    // BONUS: Try shuffling the data each epoch. Does it help?
    // BONUS: What happens with learning_rate = 0.1 vs 5.0?

    return 0;
}
