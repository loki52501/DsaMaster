// =============================================================================
// Exercise 4: Activation Functions
// =============================================================================
//
// SELF-CHECK QUESTIONS COVERED:
//   Q21. Draw the sigmoid function. What is special about its shape?
//   Q34. What is "ReLU"? Draw a plot of it for -2 to +2.
//   Q35. What is an "activation function"?
//   Q36. What's the difference between F.relu and nn.ReLU?
//   Q37. Why use more than one nonlinearity (universal approximation theorem)?
//
// =============================================================================
//
// THEORY: WHAT IS AN ACTIVATION FUNCTION?
// ───────────────────────────────────────
// An activation function is a non-linear function applied to the output of
// each neuron. Without it, a neural network is just a linear transformation,
// no matter how many layers you stack.
//
// Why? If f(x) = ax + b and g(x) = cx + d, then
//   g(f(x)) = c(ax + b) + d = (ca)x + (cb + d)
// which is STILL linear. Adding non-linear activation between layers
// lets the network learn complex, non-linear patterns.
//
// THEORY: SIGMOID
// ───────────────
// sigmoid(x) = 1 / (1 + e^(-x))
//
// Shape: an S-curve that squashes any input to range (0, 1).
// Special properties:
//   - sigmoid(0) = 0.5 (centered at zero)
//   - sigmoid(-inf) -> 0, sigmoid(+inf) -> 1
//   - Smooth and differentiable everywhere
//   - Output is always between 0 and 1 -> interpretable as probability
//   - Derivative: sigmoid(x) * (1 - sigmoid(x)), max at x=0 (0.25)
//
// THEORY: ReLU (Rectified Linear Unit)
// ────────────────────────────────────
// relu(x) = max(0, x)
//
// For x < 0: output = 0 (the neuron is "off")
// For x >= 0: output = x (linear, the neuron is "on")
//
// Why ReLU is popular:
//   - Very fast to compute (just a comparison)
//   - No vanishing gradient problem for positive values
//   - Sparse activation: many neurons output 0, which is efficient
//
// THEORY: F.relu vs nn.ReLU (PyTorch-specific)
// ─────────────────────────────────────────────
// F.relu is a FUNCTION — you call it directly: output = F.relu(x)
// nn.ReLU is a MODULE (class) — you create an instance and use it as a layer:
//   relu_layer = nn.ReLU()
//   output = relu_layer(x)
//
// They compute the same thing. nn.ReLU is used when building models as
// sequential layers. F.relu is used in forward() methods.
// In C++ terms: F.relu is a free function, nn.ReLU is a functor/class.
//
// THEORY: UNIVERSAL APPROXIMATION THEOREM
// ────────────────────────────────────────
// The theorem says: a network with ONE hidden layer and ANY non-linear
// activation can approximate any continuous function to arbitrary accuracy
// — IF the hidden layer has enough neurons.
//
// So why use MULTIPLE layers?
//   1. EFFICIENCY: One layer might need millions of neurons.
//      Multiple layers achieve the same with far fewer total parameters.
//   2. HIERARCHY: Deep networks learn features at multiple levels.
//      Layer 1: edges. Layer 2: shapes. Layer 3: objects. Layer 4: scenes.
//   3. GENERALIZATION: Deep networks generalize better in practice.
//      They learn reusable sub-features instead of memorizing everything.
//   4. In theory, 1 layer works. In practice, depth wins.
//
// =============================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

// ── Part A: Implement activation functions ───────────────────────────────────

// TODO: Implement sigmoid
double sigmoid(double x) {
    // YOUR CODE HERE
    return 0.0;
}

// TODO: Implement sigmoid derivative
// Formula: sigmoid(x) * (1 - sigmoid(x))
double sigmoidDeriv(double x) {
    // YOUR CODE HERE
    return 0.0;
}

// TODO: Implement ReLU
// Formula: max(0, x)
double relu(double x) {
    // YOUR CODE HERE
    return 0.0;
}

// TODO: Implement ReLU derivative
// 1 if x > 0, 0 otherwise
double reluDeriv(double x) {
    // YOUR CODE HERE
    return 0.0;
}

// TODO: Implement tanh activation
// Formula: (e^x - e^(-x)) / (e^x + e^(-x))  or just use std::tanh
double tanhAct(double x) {
    // YOUR CODE HERE
    return 0.0;
}

// TODO: Implement tanh derivative
// Formula: 1 - tanh(x)^2
double tanhDeriv(double x) {
    // YOUR CODE HERE
    return 0.0;
}

// ── Part B: Draw/plot activation functions (ASCII) ───────────────────────────

// This draws an ASCII plot of a function from x_min to x_max
void asciiPlot(const string& name, double (*func)(double),
               double x_min, double x_max, double y_min, double y_max) {
    const int WIDTH = 60;
    const int HEIGHT = 15;

    cout << "\n" << name << " (x: " << x_min << " to " << x_max << ")" << endl;

    char grid[HEIGHT][WIDTH];
    for (int r = 0; r < HEIGHT; r++)
        for (int c = 0; c < WIDTH; c++)
            grid[r][c] = ' ';

    // Draw axes
    int zero_row = (int)((y_max / (y_max - y_min)) * (HEIGHT - 1));
    int zero_col = (int)((-x_min / (x_max - x_min)) * (WIDTH - 1));
    if (zero_row >= 0 && zero_row < HEIGHT)
        for (int c = 0; c < WIDTH; c++) grid[zero_row][c] = '-';
    if (zero_col >= 0 && zero_col < WIDTH)
        for (int r = 0; r < HEIGHT; r++) grid[r][zero_col] = '|';

    // Plot function
    for (int c = 0; c < WIDTH; c++) {
        double x = x_min + (x_max - x_min) * c / (WIDTH - 1);
        double y = func(x);
        int r = (int)((y_max - y) / (y_max - y_min) * (HEIGHT - 1));
        if (r >= 0 && r < HEIGHT) grid[r][c] = '*';
    }

    for (int r = 0; r < HEIGHT; r++) {
        printf("%5.1f |", y_max - (y_max - y_min) * r / (HEIGHT - 1));
        for (int c = 0; c < WIDTH; c++) cout << grid[r][c];
        cout << endl;
    }
}

// ── Part C: Demonstrate why non-linearity is essential ───────────────────────

void linearityDemo() {
    cout << "\n=== Why Non-Linearity Matters ===" << endl;

    // Two "linear layers" stacked: f(x) = 3x + 1, g(x) = 2x - 1
    // g(f(x)) = 2*(3x + 1) - 1 = 6x + 1 — still linear!
    double x = 5.0;
    double layer1 = 3 * x + 1;      // 16
    double layer2 = 2 * layer1 - 1;  // 31
    double collapsed = 6 * x + 1;    // 31 — identical!

    cout << "Two linear layers: g(f(x)) where f(x)=3x+1, g(x)=2x-1" << endl;
    cout << "  f(" << x << ") = " << layer1 << endl;
    cout << "  g(f(" << x << ")) = " << layer2 << endl;
    cout << "  Collapsed single layer: 6*" << x << "+1 = " << collapsed << endl;
    cout << "  They're identical! Stacking linear layers is pointless." << endl;

    // With non-linearity (ReLU between layers):
    double with_relu = 2 * relu(3 * x + 1) - 1;  // relu doesn't change positive
    double neg_x = -5.0;
    double linear_neg = 6 * neg_x + 1;  // -29
    double nonlinear_neg = 2 * relu(3 * neg_x + 1) - 1;  // relu(3*(-5)+1) = relu(-14) = 0, so 2*0-1 = -1

    cout << "\nWith ReLU between layers:" << endl;
    cout << "  x=" << neg_x << ": linear=" << linear_neg
         << " vs nonlinear=" << nonlinear_neg << endl;
    cout << "  Different! ReLU creates a non-linear function." << endl;
}

// =============================================================================

int main() {
    // Test activation functions
    cout << "=== Activation Functions ===" << endl;
    cout << "\n  x\t| Sigmoid\t| ReLU\t\t| Tanh" << endl;
    cout << "  ------+---------------+---------------+--------" << endl;
    vector<double> test_vals = {-3, -2, -1, -0.5, 0, 0.5, 1, 2, 3};
    for (double x : test_vals) {
        printf("  %4.1f\t| %8.4f\t| %8.4f\t| %8.4f\n",
               x, sigmoid(x), relu(x), tanhAct(x));
    }

    cout << "\nDerivatives:" << endl;
    cout << "  x\t| Sigmoid'\t| ReLU'\t\t| Tanh'" << endl;
    cout << "  ------+---------------+---------------+--------" << endl;
    for (double x : test_vals) {
        printf("  %4.1f\t| %8.4f\t| %8.4f\t| %8.4f\n",
               x, sigmoidDeriv(x), reluDeriv(x), tanhDeriv(x));
    }

    // Draw ASCII plots
    asciiPlot("SIGMOID", sigmoid, -6, 6, -0.2, 1.2);
    asciiPlot("ReLU", relu, -2, 2, -0.5, 2.5);
    asciiPlot("TANH", tanhAct, -4, 4, -1.2, 1.2);

    linearityDemo();

    cout << "\n=== Summary ===" << endl;
    cout << "Sigmoid: S-curve, output (0,1), used for binary output layers" << endl;
    cout << "ReLU:    max(0,x), fast, used in most hidden layers" << endl;
    cout << "Tanh:    S-curve, output (-1,1), centered version of sigmoid" << endl;
    cout << "\nF.relu vs nn.ReLU (PyTorch):" << endl;
    cout << "  F.relu = free function, nn.ReLU = module/class. Same math." << endl;
    cout << "\nUniversal Approximation Theorem:" << endl;
    cout << "  1 hidden layer CAN approximate anything, but deep networks" << endl;
    cout << "  do it with far fewer parameters and generalize better." << endl;

    return 0;
}
