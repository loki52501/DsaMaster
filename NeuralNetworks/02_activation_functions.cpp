// =============================================================================
// Exercise 2: Activation Functions
// =============================================================================
// Activation functions introduce non-linearity into the network.
// Without them, stacking layers would just be a linear transformation.
//
// YOUR TASK:
//   1. Implement sigmoid() and sigmoidDerivative()
//   2. Implement relu() and reluDerivative()
//   3. Implement tanhActivation() and tanhDerivative()
//   4. Run and compare their outputs for the test values
// =============================================================================

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// --- SIGMOID ---
// Maps input to range (0, 1)
// Formula: 1 / (1 + e^(-x))
// Use case: output layer for binary classification
double sigmoid(double x) {
    // YOUR CODE HERE
    return 0.0;
}

// Derivative: sigmoid(x) * (1 - sigmoid(x))
double sigmoidDerivative(double x) {
    // YOUR CODE HERE
    return 0.0;
}

// --- ReLU (Rectified Linear Unit) ---
// Maps input to max(0, x)
// Use case: hidden layers (most common choice)
double relu(double x) {
    // YOUR CODE HERE
    return 0.0;
}

// Derivative: 1 if x > 0, else 0
double reluDerivative(double x) {
    // YOUR CODE HERE
    return 0.0;
}

// --- TANH ---
// Maps input to range (-1, 1)
// Formula: (e^x - e^(-x)) / (e^x + e^(-x))
// Use case: hidden layers when you want centered outputs
double tanhActivation(double x) {
    // YOUR CODE HERE
    // Hint: C++ has a built-in tanh() function you can use
    return 0.0;
}

// Derivative: 1 - tanh(x)^2
double tanhDerivative(double x) {
    // YOUR CODE HERE
    return 0.0;
}

void testActivation(const string& name,
                    double (*func)(double),
                    double (*deriv)(double),
                    const vector<double>& testValues) {
    cout << "=== " << name << " ===" << endl;
    cout << "  x\t| f(x)\t\t| f'(x)" << endl;
    cout << "  ------+---------------+---------" << endl;
    for (double x : testValues) {
        printf("  %.1f\t| %.6f\t| %.6f\n", x, func(x), deriv(x));
    }
    cout << endl;
}

int main() {
    vector<double> testValues = {-3.0, -1.0, 0.0, 1.0, 3.0};

    testActivation("Sigmoid", sigmoid, sigmoidDerivative, testValues);
    testActivation("ReLU", relu, reluDerivative, testValues);
    testActivation("Tanh", tanhActivation, tanhDerivative, testValues);

    // Expected outputs for verification:
    //
    // Sigmoid:
    //   sigmoid(-3) ~= 0.0474,  sigmoid(0) = 0.5,  sigmoid(3) ~= 0.9526
    //
    // ReLU:
    //   relu(-3) = 0,  relu(0) = 0,  relu(3) = 3
    //
    // Tanh:
    //   tanh(-3) ~= -0.9951,  tanh(0) = 0,  tanh(3) ~= 0.9951
    //
    // QUESTION: Why can't we just use a linear activation f(x) = x?
    // Think about what happens when you stack two linear layers:
    //   Layer 1: y = w1*x + b1
    //   Layer 2: z = w2*y + b2 = w2*(w1*x + b1) + b2 = (w2*w1)*x + (w2*b1 + b2)
    // It collapses to a single linear transformation! Non-linearity is essential.

    return 0;
}
