// =============================================================================
// Exercise 6: Neurons, Bias, and Forward Pass
// =============================================================================
//
// SELF-CHECK QUESTIONS COVERED:
//   Q27. What does `view` do in PyTorch?
//   Q28. What are "bias" parameters? Why do we need them?
//   Q29. What does the `@` operator do in Python?
//
// =============================================================================
//
// THEORY: BIAS PARAMETERS
// ───────────────────────
// A bias is a constant added to the weighted sum BEFORE the activation:
//   output = activation(w1*x1 + w2*x2 + ... + BIAS)
//
// WHY do we need bias?
// Without bias, the neuron's decision boundary must pass through the origin.
// Example: sigmoid(w*x) always outputs 0.5 when x=0, regardless of w.
// With bias: sigmoid(w*x + b). Setting b shifts the sigmoid left/right.
//
// Think of it this way:
//   - Weights control the SLOPE of the decision boundary
//   - Bias controls the POSITION (offset) of the decision boundary
//   - Without bias, you can only rotate the line, not translate it
//
// THEORY: MATRIX MULTIPLICATION (@ operator in Python)
// ────────────────────────────────────────────────────
// In Python/PyTorch, the @ operator does matrix multiplication.
//   result = inputs @ weights   (equivalent to np.dot or torch.mm)
//
// Matrix multiply: [m x n] @ [n x p] = [m x p]
// Each output element is a dot product of a row and column:
//   C[i][j] = sum(A[i][k] * B[k][j]) for all k
//
// In a neural network:
//   inputs: [batch_size x n_inputs]
//   weights: [n_inputs x n_neurons]
//   result = inputs @ weights -> [batch_size x n_neurons]
//
// This computes ALL neurons for ALL samples in one operation!
// Much faster than looping through each neuron individually.
//
// THEORY: VIEW (PyTorch)
// ──────────────────────
// `view` reshapes a tensor without changing its data.
// It changes how you interpret the same block of memory.
//
// Example:
//   x = tensor with 784 elements (a flat 28*28 image)
//   x.view(28, 28)  -> reshapes to a 28x28 matrix
//   x.view(1, 784)  -> reshapes to a 1x784 row vector
//   x.view(-1)       -> flattens to a 1D vector (-1 = "figure out this dim")
//
// This is crucial for neural networks:
//   - Images come as 28x28 matrices
//   - Neural network input layers expect flat vectors [784]
//   - view(784) or view(-1) flattens the image for the network
//
// In C++ equivalent: it's like casting a 2D array to a 1D pointer.
//
// =============================================================================

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// ── Part A: Why Bias Matters ─────────────────────────────────────────────────

// TODO Part A: Demonstrate that without bias, a neuron can't learn simple offsets
void biasDemo() {
    cout << "=== Why We Need Bias ===" << endl;

    double x = 0.0;  // input is zero

    // Without bias: output is always sigmoid(0) = 0.5, regardless of weight
    double w = 5.0;
    double no_bias = sigmoid(w * x);
    cout << "Without bias (x=0): sigmoid(" << w << " * 0) = " << no_bias << endl;
    cout << "  No matter what weight we choose, output at x=0 is ALWAYS 0.5!" << endl;

    // With bias: we can shift the output
    double bias = -3.0;
    double with_bias = sigmoid(w * x + bias);
    cout << "\nWith bias=-3 (x=0): sigmoid(" << w << " * 0 + " << bias << ") = "
         << with_bias << endl;

    bias = 3.0;
    with_bias = sigmoid(w * x + bias);
    cout << "With bias=+3 (x=0): sigmoid(" << w << " * 0 + " << bias << ") = "
         << with_bias << endl;

    cout << "\nBias lets us shift the activation function left/right!" << endl;
    cout << "Without it, the decision boundary is stuck through the origin." << endl;
}

// ── Part B: Matrix Multiplication (the @ operator) ───────────────────────────

// TODO Part B: Implement matrix multiplication
// A[m][n] @ B[n][p] = C[m][p]
// C[i][j] = sum of A[i][k] * B[k][j] for k = 0..n-1
void matmul(const vector<vector<double>>& A,
            const vector<vector<double>>& B,
            vector<vector<double>>& C) {
    int m = A.size();
    int n = A[0].size();
    int p = B[0].size();
    C.assign(m, vector<double>(p, 0.0));

    // YOUR CODE HERE
    // Triple nested loop: for each i, j, k
    //   C[i][j] += A[i][k] * B[k][j]
}

// ── Part C: Forward Pass Using Matrix Multiplication ─────────────────────────

// TODO Part C: Implement a forward pass for a layer using matmul + bias
// This is what a real neural network layer does:
//   output = activation(inputs @ weights + bias)
vector<vector<double>> forwardLayer(
    const vector<vector<double>>& inputs,   // [batch_size x n_inputs]
    const vector<vector<double>>& weights,   // [n_inputs x n_neurons]
    const vector<double>& biases)            // [n_neurons]
{
    // YOUR CODE HERE
    // 1. Compute matmul(inputs, weights) -> result [batch_size x n_neurons]
    // 2. Add biases to each row: result[i][j] += biases[j]  (broadcasting!)
    // 3. Apply sigmoid to each element
    // 4. Return result

    vector<vector<double>> result;
    return result; // placeholder
}

// ── Part D: View / Reshape ───────────────────────────────────────────────────

// Demonstrate reshaping: flatten a 2D image to 1D for network input
void viewDemo() {
    cout << "\n=== View / Reshape ===" << endl;

    // A 3x3 "image"
    int image[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

    // Flatten to 1D (like PyTorch's .view(-1) or .view(9))
    int flat[9];
    int idx = 0;
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            flat[idx++] = image[r][c];

    cout << "Original 3x3 image:" << endl;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) cout << image[r][c] << " ";
        cout << endl;
    }

    cout << "\nFlattened (view(-1)) to 1D vector: ";
    for (int i = 0; i < 9; i++) cout << flat[i] << " ";
    cout << endl;

    cout << "\nIn PyTorch:" << endl;
    cout << "  x = torch.tensor([[1,2,3],[4,5,6],[7,8,9]])" << endl;
    cout << "  x.view(-1)    -> tensor([1,2,3,4,5,6,7,8,9])  # flatten" << endl;
    cout << "  x.view(1, 9)  -> tensor([[1,2,3,4,5,6,7,8,9]]) # row vector" << endl;
    cout << "  x.view(9, 1)  -> column vector" << endl;
    cout << "  Same data, different shape. No copy needed." << endl;
}

// ── Part E: Complete Forward Pass ────────────────────────────────────────────

void fullForwardPass() {
    cout << "\n=== Full Forward Pass (2 inputs -> 2 hidden -> 1 output) ===" << endl;

    // 2 samples, each with 2 inputs (like a mini-batch of size 2)
    vector<vector<double>> inputs = {{0.5, 0.8}, {0.1, 0.9}};

    // Hidden layer: 2 inputs -> 2 neurons
    vector<vector<double>> w_hidden = {{0.15, 0.25},   // weights from input 0
                                        {0.20, 0.30}};  // weights from input 1
    vector<double> b_hidden = {0.35, 0.35};

    // Output layer: 2 inputs (from hidden) -> 1 neuron
    vector<vector<double>> w_output = {{0.40},    // weight from hidden 0
                                        {0.45}};   // weight from hidden 1
    vector<double> b_output = {0.60};

    // Layer 1: hidden = sigmoid(inputs @ w_hidden + b_hidden)
    vector<vector<double>> hidden = forwardLayer(inputs, w_hidden, b_hidden);

    if (hidden.empty()) {
        cout << "  (implement forwardLayer to see results)" << endl;
        return;
    }

    cout << "Hidden layer outputs:" << endl;
    for (int i = 0; i < (int)hidden.size(); i++) {
        cout << "  Sample " << i << ": ";
        for (double v : hidden[i]) printf("%.4f ", v);
        cout << endl;
    }

    // Layer 2: output = sigmoid(hidden @ w_output + b_output)
    vector<vector<double>> output = forwardLayer(hidden, w_output, b_output);

    cout << "\nFinal outputs:" << endl;
    for (int i = 0; i < (int)output.size(); i++) {
        cout << "  Sample " << i << ": " << output[i][0] << endl;
    }

    cout << "\nNotice: we processed 2 samples at once using matrix multiplication!" << endl;
    cout << "This is batched computation — the @ operator handles it all." << endl;
}

// =============================================================================

int main() {
    biasDemo();

    // Test matmul
    cout << "\n=== Matrix Multiplication (@) ===" << endl;
    vector<vector<double>> A = {{1, 2}, {3, 4}};   // 2x2
    vector<vector<double>> B = {{5, 6}, {7, 8}};   // 2x2
    vector<vector<double>> C;
    matmul(A, B, C);

    cout << "A @ B =" << endl;
    if (!C.empty()) {
        for (auto& row : C) {
            cout << "  ";
            for (double v : row) cout << v << " ";
            cout << endl;
        }
        cout << "Expected: 19 22 / 43 50" << endl;
    } else {
        cout << "  (implement matmul to see results)" << endl;
    }

    viewDemo();
    fullForwardPass();

    cout << "\n=== In Python/PyTorch ===" << endl;
    cout << "inputs @ weights  is  matrix multiplication" << endl;
    cout << "x.view(-1)        reshapes tensor without copying data" << endl;
    cout << "bias              shifts the activation, essential for learning" << endl;

    return 0;
}
