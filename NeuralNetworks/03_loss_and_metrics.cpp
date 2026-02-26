// =============================================================================
// Exercise 3: Loss Functions and Metrics
// =============================================================================
//
// SELF-CHECK QUESTIONS COVERED:
//   Q11. Are metrics calculated on training or validation set? Why?
//   Q16. What is "loss"?
//   Q20. Why can't we use accuracy as a loss function?
//   Q22. What is the difference between a loss function and a metric?
//
// =============================================================================
//
// THEORY: LOSS vs METRIC
// ──────────────────────
// A LOSS FUNCTION is what the model optimizes during training.
// Requirements for a loss function:
//   - Must be DIFFERENTIABLE (we need to compute gradients)
//   - Must be SMOOTH (small weight changes -> small loss changes)
//   - Must decrease as predictions improve
//
// A METRIC is what WE (humans) care about.
//   - Accuracy is a metric: "what % did the model get right?"
//   - Doesn't need to be differentiable — it's just for reporting.
//
// WHY CAN'T ACCURACY BE A LOSS FUNCTION?
// ───────────────────────────────────────
// Accuracy = (number correct) / (total predictions)
//
// Problem: Accuracy is NOT differentiable. It's a step function.
// If a model predicts 0.499 for a threshold of 0.5, it's "wrong" (accuracy=0).
// If it predicts 0.501, it's "right" (accuracy=1).
// A tiny weight change that pushes 0.499 to 0.500001 causes a HUGE jump
// in accuracy (0->1), but gradient descent needs smooth, gradual changes.
//
// MSE and cross-entropy ARE smooth: changing a prediction from 0.499 to 0.501
// causes a tiny, proportional change in loss. Gradient descent can use this!
//
// THEORY: TRAINING SET vs VALIDATION SET
// ──────────────────────────────────────
// Metrics should be calculated on the VALIDATION set, NOT the training set.
//
// Why? The model has already "seen" the training data and optimized for it.
// Measuring accuracy on training data is like grading a student on questions
// they've already seen — it doesn't measure real understanding.
//
// The validation set contains data the model has NEVER trained on.
// Performance on validation = how well the model GENERALIZES to new data.
// If training accuracy is high but validation accuracy is low -> OVERFITTING.
//
// THEORY: WHAT IS LOSS?
// ─────────────────────
// "Loss" is a single number that measures how wrong the model is.
// The goal of training is to MINIMIZE the loss.
//   - Loss = 0 means perfect predictions.
//   - Higher loss means worse predictions.
// The choice of loss function depends on the problem:
//   - Regression (predict a number): MSE, RMSE
//   - Classification (predict a class): Cross-Entropy
//
// =============================================================================

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// ── Part A: Loss Functions ───────────────────────────────────────────────────

// TODO Part A1: Implement Mean Squared Error
// Formula: MSE = (1/n) * sum((predicted[i] - actual[i])^2)
double mse(const vector<double>& pred, const vector<double>& actual) {
    // YOUR CODE HERE

    return 0.0; // placeholder
}

// TODO Part A2: Implement Binary Cross-Entropy
// Formula: BCE = -(1/n) * sum(actual*log(pred) + (1-actual)*log(1-pred))
// Add epsilon (1e-15) inside log() to avoid log(0).
double binaryCrossEntropy(const vector<double>& pred, const vector<double>& actual) {
    // YOUR CODE HERE

    return 0.0; // placeholder
}

// ── Part B: Metrics ──────────────────────────────────────────────────────────

// TODO Part B1: Implement accuracy metric
// Accuracy = number of correct predictions / total predictions
// A prediction is "correct" if (pred > 0.5) matches (actual > 0.5)
double accuracy(const vector<double>& pred, const vector<double>& actual) {
    // YOUR CODE HERE

    return 0.0; // placeholder
}

// ── Part C: Why accuracy can't be a loss function ────────────────────────────

// This function demonstrates WHY accuracy is useless for gradient descent.
// It shows that tiny weight changes don't change accuracy at all,
// but DO change MSE — which is what gradient descent needs.
void demonstrateAccuracyProblem() {
    cout << "\n=== Why Accuracy Can't Be a Loss Function ===" << endl;

    vector<double> actual = {1.0, 0.0, 1.0, 0.0};

    // Predictions just below and just above threshold
    vector<double> pred_below = {0.49, 0.51, 0.49, 0.51};  // all wrong!
    vector<double> pred_above = {0.51, 0.49, 0.51, 0.49};  // all right!
    vector<double> pred_tiny  = {0.50, 0.50, 0.50, 0.50};  // on the edge

    cout << "Predictions slightly below threshold:" << endl;
    cout << "  Accuracy: " << accuracy(pred_below, actual)
         << "  MSE: " << mse(pred_below, actual) << endl;

    cout << "Predictions slightly above threshold:" << endl;
    cout << "  Accuracy: " << accuracy(pred_above, actual)
         << "  MSE: " << mse(pred_above, actual) << endl;

    // KEY INSIGHT: accuracy jumps from 0% to 100% with a 0.02 change
    // in predictions, but MSE changes SMOOTHLY.
    // Gradient descent needs smooth changes to compute useful gradients.
    // A flat function (accuracy stays 0 until threshold) has gradient = 0,
    // so the model can't learn which direction to adjust weights!

    cout << "\nKey insight:" << endl;
    cout << "  Accuracy jumped from 0% to 100% with tiny change -> NOT smooth!" << endl;
    cout << "  MSE changed gradually -> smooth, differentiable, gradient works!" << endl;
}

// ── Part D: Training vs Validation ───────────────────────────────────────────

void demonstrateOverfitting() {
    cout << "\n=== Training vs Validation Metrics ===" << endl;

    // Simulated scenario: model memorizes training data but doesn't generalize
    // Training predictions (model has seen this data)
    vector<double> train_pred   = {0.95, 0.02, 0.98, 0.01, 0.99};
    vector<double> train_actual = {1.0,  0.0,  1.0,  0.0,  1.0};

    // Validation predictions (model has NEVER seen this data)
    vector<double> val_pred   = {0.6, 0.4, 0.7, 0.45, 0.55};
    vector<double> val_actual = {1.0, 0.0, 1.0, 0.0,  1.0};

    cout << "Training set:" << endl;
    cout << "  Accuracy: " << accuracy(train_pred, train_actual) * 100 << "%" << endl;
    cout << "  Loss:     " << mse(train_pred, train_actual) << endl;

    cout << "\nValidation set:" << endl;
    cout << "  Accuracy: " << accuracy(val_pred, val_actual) * 100 << "%" << endl;
    cout << "  Loss:     " << mse(val_pred, val_actual) << endl;

    cout << "\nThe training accuracy is great, but validation is poor." << endl;
    cout << "This is OVERFITTING — the model memorized training data" << endl;
    cout << "but doesn't generalize. That's why we measure on VALIDATION set!" << endl;
}

// =============================================================================

int main() {
    cout << "=== Loss Functions and Metrics ===" << endl << endl;

    // Test data
    vector<double> actual = {1.0, 0.0, 1.0, 0.0};

    // Good predictions
    vector<double> good_pred = {0.9, 0.1, 0.85, 0.15};
    cout << "Good predictions: ";
    for (double p : good_pred) cout << p << " ";
    cout << endl;
    cout << "  MSE:  " << mse(good_pred, actual) << endl;
    cout << "  BCE:  " << binaryCrossEntropy(good_pred, actual) << endl;
    cout << "  Acc:  " << accuracy(good_pred, actual) * 100 << "%" << endl;

    // Bad predictions
    vector<double> bad_pred = {0.2, 0.8, 0.3, 0.7};
    cout << "\nBad predictions: ";
    for (double p : bad_pred) cout << p << " ";
    cout << endl;
    cout << "  MSE:  " << mse(bad_pred, actual) << endl;
    cout << "  BCE:  " << binaryCrossEntropy(bad_pred, actual) << endl;
    cout << "  Acc:  " << accuracy(bad_pred, actual) * 100 << "%" << endl;

    demonstrateAccuracyProblem();
    demonstrateOverfitting();

    return 0;
}
