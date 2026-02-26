// =============================================================================
// Exercise 5: Backpropagation — Learning the AND Gate
// =============================================================================
// Backpropagation computes how much each weight contributed to the error,
// then adjusts weights to reduce that error.
//
// We'll train a single neuron to learn the AND gate:
//   (0,0) -> 0
//   (0,1) -> 0
//   (1,0) -> 0
//   (1,1) -> 1
//
// YOUR TASK:
//   1. Implement sigmoid() and sigmoidDerivative()
//   2. Implement computeGradients() — the chain rule in action
//   3. Implement updateWeights() — gradient descent
//   4. Run training and watch the loss decrease!
// =============================================================================

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double sigmoid(double x) {
    // YOUR CODE HERE
    return 0.0;
}

double sigmoidDerivative(double x) {
    // YOUR CODE HERE
    // Hint: sigmoid(x) * (1 - sigmoid(x))
    return 0.0;
}

struct Neuron {
    double w1, w2, bias;
    double learning_rate;
};

// Forward pass for a single neuron
double forward(const Neuron& n, double x1, double x2) {
    double z = n.w1 * x1 + n.w2 * x2 + n.bias;
    return sigmoid(z);
}

// TODO: Compute gradients using the chain rule
// The chain rule for a single neuron:
//
//   Loss = (predicted - actual)^2
//   dLoss/dPredicted = 2 * (predicted - actual)
//   dPredicted/dZ    = sigmoid'(z) = predicted * (1 - predicted)
//   dZ/dW1           = x1
//   dZ/dW2           = x2
//   dZ/dBias         = 1
//
//   dLoss/dW1   = dLoss/dPredicted * dPredicted/dZ * dZ/dW1
//   dLoss/dW2   = dLoss/dPredicted * dPredicted/dZ * dZ/dW2
//   dLoss/dBias = dLoss/dPredicted * dPredicted/dZ * dZ/dBias
//
// Fill in grad_w1, grad_w2, grad_bias
void computeGradients(double x1, double x2, double predicted, double actual,
                      double& grad_w1, double& grad_w2, double& grad_bias) {
    // YOUR CODE HERE

    // Step 1: dLoss/dPredicted
    // double dLoss_dPred = ???

    // Step 2: dPredicted/dZ (sigmoid derivative, using the output)
    // double dPred_dZ = ???

    // Step 3: Combine with chain rule
    // double delta = dLoss_dPred * dPred_dZ;

    // Step 4: Compute gradients for each parameter
    // grad_w1 = ???
    // grad_w2 = ???
    // grad_bias = ???

    grad_w1 = 0.0;   // placeholder
    grad_w2 = 0.0;   // placeholder
    grad_bias = 0.0;  // placeholder
}

// TODO: Update weights using gradient descent
// Formula: weight = weight - learning_rate * gradient
void updateWeights(Neuron& n, double grad_w1, double grad_w2, double grad_bias) {
    // YOUR CODE HERE

}

int main() {
    // AND gate training data
    double inputs[][2] = {{0,0}, {0,1}, {1,0}, {1,1}};
    double targets[]   = { 0,     0,     0,     1   };
    int n_samples = 4;

    // Initialize neuron with small random-ish weights
    Neuron neuron;
    neuron.w1 = 0.5;
    neuron.w2 = 0.5;
    neuron.bias = -0.2;
    neuron.learning_rate = 1.0;

    int epochs = 10000;

    cout << "=== Training AND Gate ===" << endl;
    cout << "Initial weights: w1=" << neuron.w1
         << " w2=" << neuron.w2
         << " bias=" << neuron.bias << endl << endl;

    for (int epoch = 0; epoch < epochs; epoch++) {
        double total_loss = 0.0;

        for (int i = 0; i < n_samples; i++) {
            double x1 = inputs[i][0];
            double x2 = inputs[i][1];
            double target = targets[i];

            // Forward pass
            double predicted = forward(neuron, x1, x2);

            // Compute loss
            double loss = (predicted - target) * (predicted - target);
            total_loss += loss;

            // Compute gradients
            double grad_w1, grad_w2, grad_bias;
            computeGradients(x1, x2, predicted, target, grad_w1, grad_w2, grad_bias);

            // Update weights
            updateWeights(neuron, grad_w1, grad_w2, grad_bias);
        }

        // Print progress every 1000 epochs
        if (epoch % 1000 == 0) {
            cout << "Epoch " << epoch << " | Loss: " << total_loss / n_samples << endl;
        }
    }

    // Test the trained neuron
    cout << "\n=== Results ===" << endl;
    cout << "Final weights: w1=" << neuron.w1
         << " w2=" << neuron.w2
         << " bias=" << neuron.bias << endl;
    cout << endl;

    for (int i = 0; i < n_samples; i++) {
        double output = forward(neuron, inputs[i][0], inputs[i][1]);
        cout << "Input: (" << inputs[i][0] << ", " << inputs[i][1]
             << ") -> " << output
             << " (expected: " << targets[i] << ")"
             << (((output > 0.5) == (targets[i] > 0.5)) ? " OK" : " WRONG")
             << endl;
    }

    // SUCCESS CRITERIA:
    // - Loss should decrease over epochs
    // - (0,0)->~0, (0,1)->~0, (1,0)->~0, (1,1)->~1
    // - All outputs should round to their expected values

    return 0;
}
