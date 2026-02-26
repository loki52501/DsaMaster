// =============================================================================
// Exercise 3: Forward Pass
// =============================================================================
// A forward pass pushes input through the network layer by layer
// to produce an output.
//
// Network architecture:
//   2 inputs -> 2 hidden neurons -> 1 output neuron
//
//   x1 --w1--> h1 --w5-->
//       \  /         \
//        \/           --> o1
//        /\           /
//       /  \         /
//   x2 --w3--> h2 --w6-->
//
//   (w1, w2 go into h1)
//   (w3, w4 go into h2)
//   (w5, w6 go into o1)
//
// YOUR TASK:
//   1. Implement sigmoid() (reuse from exercise 1)
//   2. Implement forwardPass() — compute hidden layer, then output layer
//   3. Verify your output matches the expected value
// =============================================================================

#include <iostream>
#include <cmath>
using namespace std;

double sigmoid(double x) {
    // YOUR CODE HERE (same as exercise 1)
    return 0.0;
}

struct Network {
    // Hidden layer weights (2 neurons, each with 2 inputs)
    double w1, w2;  // weights into hidden neuron 1
    double w3, w4;  // weights into hidden neuron 2
    double b_h1, b_h2;  // biases for hidden neurons

    // Output layer weights (1 neuron with 2 inputs from hidden layer)
    double w5, w6;  // weights into output neuron
    double b_o;     // bias for output neuron
};

// TODO: Implement the forward pass
// Step 1: Compute hidden neuron 1: h1 = sigmoid(w1*x1 + w2*x2 + b_h1)
// Step 2: Compute hidden neuron 2: h2 = sigmoid(w3*x1 + w4*x2 + b_h2)
// Step 3: Compute output:          o  = sigmoid(w5*h1 + w6*h2 + b_o)
// Return the final output value
double forwardPass(const Network& net, double x1, double x2) {
    // YOUR CODE HERE

    // Step 1: compute h1

    // Step 2: compute h2

    // Step 3: compute output using h1 and h2

    return 0.0; // placeholder
}

int main() {
    Network net;

    // Set weights (these are pre-chosen, don't change for verification)
    net.w1 = 0.15; net.w2 = 0.20;   // -> h1
    net.w3 = 0.25; net.w4 = 0.30;   // -> h2
    net.b_h1 = 0.35; net.b_h2 = 0.35;

    net.w5 = 0.40; net.w6 = 0.45;   // -> output
    net.b_o = 0.60;

    double x1 = 0.05, x2 = 0.10;

    double output = forwardPass(net, x1, x2);

    cout << "=== Forward Pass ===" << endl;
    cout << "Input: x1=" << x1 << ", x2=" << x2 << endl;
    cout << "Output: " << output << endl;

    // Let's trace the expected calculation:
    // h1_z = 0.15*0.05 + 0.20*0.10 + 0.35 = 0.0075 + 0.02 + 0.35 = 0.3775
    // h1   = sigmoid(0.3775) ~= 0.5933
    //
    // h2_z = 0.25*0.05 + 0.30*0.10 + 0.35 = 0.0125 + 0.03 + 0.35 = 0.3925
    // h2   = sigmoid(0.3925) ~= 0.5969
    //
    // o_z  = 0.40*0.5933 + 0.45*0.5969 + 0.60 = 0.2373 + 0.2686 + 0.60 = 1.1059
    // o    = sigmoid(1.1059) ~= 0.7514

    cout << "\nExpected output: ~0.7514" << endl;
    cout << "Your output is " << (abs(output - 0.7514) < 0.01 ? "CORRECT!" : "INCORRECT") << endl;

    // BONUS: Print the intermediate hidden layer values (h1 and h2)
    // to verify each step independently.

    return 0;
}
