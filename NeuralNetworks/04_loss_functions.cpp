// =============================================================================
// Exercise 4: Loss Functions
// =============================================================================
// A loss function measures how wrong our network's predictions are.
// The goal of training is to MINIMIZE the loss.
//
// YOUR TASK:
//   1. Implement meanSquaredError()
//   2. Implement binaryCrossEntropy()
//   3. Compare how they behave on the test cases
// =============================================================================

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// TODO: Implement Mean Squared Error
// Formula: MSE = (1/n) * sum((predicted[i] - actual[i])^2)
//
// This is the most intuitive loss: average of squared differences.
// Used for regression problems.
double meanSquaredError(const vector<double>& predicted, const vector<double>& actual) {
    // YOUR CODE HERE
    // 1. Loop through all predictions
    // 2. Compute (predicted[i] - actual[i])^2 for each
    // 3. Return the average

    return 0.0; // placeholder
}

// TODO: Implement Binary Cross-Entropy Loss
// Formula: BCE = -(1/n) * sum(actual[i]*log(pred[i]) + (1-actual[i])*log(1-pred[i]))
//
// Better than MSE for classification because it heavily penalizes
// confident wrong predictions.
double binaryCrossEntropy(const vector<double>& predicted, const vector<double>& actual) {
    // YOUR CODE HERE
    // 1. Loop through all predictions
    // 2. For each: actual*log(predicted) + (1-actual)*log(1-predicted)
    // 3. Return the negative average
    // Hint: add a small epsilon (1e-15) inside log() to avoid log(0)

    return 0.0; // placeholder
}

int main() {
    cout << "=== Loss Functions ===" << endl << endl;

    // Test Case 1: Perfect predictions
    vector<double> pred1 = {1.0, 0.0, 1.0};
    vector<double> actual = {1.0, 0.0, 1.0};
    cout << "Case 1: Perfect predictions" << endl;
    cout << "  MSE: " << meanSquaredError(pred1, actual) << " (expected: 0.0)" << endl;
    cout << "  BCE: " << binaryCrossEntropy(pred1, actual) << " (expected: ~0.0)" << endl;
    cout << endl;

    // Test Case 2: Slightly off
    vector<double> pred2 = {0.9, 0.1, 0.8};
    cout << "Case 2: Slightly off predictions" << endl;
    cout << "  MSE: " << meanSquaredError(pred2, actual) << " (expected: ~0.02)" << endl;
    cout << "  BCE: " << binaryCrossEntropy(pred2, actual) << " (expected: ~0.145)" << endl;
    cout << endl;

    // Test Case 3: Very wrong predictions
    vector<double> pred3 = {0.1, 0.9, 0.2};
    cout << "Case 3: Very wrong predictions" << endl;
    cout << "  MSE: " << meanSquaredError(pred3, actual) << " (expected: ~0.6067)" << endl;
    cout << "  BCE: " << binaryCrossEntropy(pred3, actual) << " (expected: ~2.12)" << endl;
    cout << endl;

    // OBSERVATION:
    // Notice how BCE penalizes wrong predictions much more harshly than MSE.
    // When predicted=0.1 but actual=1.0, BCE gives -log(0.1) = 2.30!
    // This strong gradient helps the network learn faster for classification.

    // BONUS QUESTION:
    // Why do we use MSE for regression but BCE for classification?
    // Think about what the gradients look like for each.

    return 0;
}
