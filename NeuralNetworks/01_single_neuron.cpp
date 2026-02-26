// =============================================================================
// Exercise 1: Single Neuron
// =============================================================================
// A single neuron takes inputs, multiplies by weights, adds a bias,
// and passes the result through an activation function.
//
//   output = sigmoid(w1*x1 + w2*x2 + bias)
//
// YOUR TASK:
//   1. Implement sigmoid()
//   2. Implement computeOutput()
//   3. Run and verify the output is between 0 and 1
// =============================================================================

#include <iostream>
#include <cmath>
using namespace std;

// TODO: Implement the sigmoid activation function
// Formula: sigmoid(x) = 1.0 / (1.0 + exp(-x))
double sigmoid(double x) {
    // YOUR CODE HERE

    return 1/(1+exp(-x)); // placeholder
}

// TODO: Implement a single neuron computation
// Steps:
//   1. Compute weighted sum: z = w1*x1 + w2*x2 + bias
//   2. Apply sigmoid activation: output = sigmoid(z)
double computeOutput(double x1, double x2, double w1, double w2, double bias) {
    // YOUR CODE HERE
    double z=w1*x1+w2*x2+bias;
    return sigmoid(z); // placeholder
}

int main() {
    // Inputs
    double x1 = 0.5;
    double x2 = 0.8;

    // Weights and bias (try changing these!)
    double w1 = 0.4;
    double w2 = 0.6;
    double bias = -0.3;

    double output = computeOutput(x1, x2, w1, w2, bias);

    cout << "=== Single Neuron ===" << endl;
    cout << "Inputs:  x1=" << x1 << ", x2=" << x2 << endl;
    cout << "Weights: w1=" << w1 << ", w2=" << w2 << endl;
    cout << "Bias:    " << bias << endl;
    cout << "Output:  " << output << endl;

    // Verification
    // Weighted sum: 0.4*0.5 + 0.6*0.8 + (-0.3) = 0.2 + 0.48 - 0.3 = 0.38
    // sigmoid(0.38) ~= 0.5938
    cout << "\nExpected output: ~0.5938" << endl;
    cout << "Your output is " << (abs(output - 0.5938) < 0.01 ? "CORRECT!" : "INCORRECT - keep trying!") << endl;

    // BONUS: Try these experiments after you get it working:
    // 1. What happens when you set bias = -10? Why?
    // 2. What happens when you set bias = 10? Why?
    // 3. What happens when all weights are 0?

    return 0;
}
