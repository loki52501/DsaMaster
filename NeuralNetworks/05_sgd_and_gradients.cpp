// =============================================================================
// Exercise 5: SGD and Gradients
// =============================================================================
//
// SELF-CHECK QUESTIONS COVERED:
//   Q12. What is SGD?
//   Q13. Why does SGD use mini-batches?
//   Q14. What are the seven steps in SGD for machine learning?
//   Q15. How do we initialize the weights in a model?
//   Q17. Why can't we always use a high learning rate?
//   Q18. What is a "gradient"?
//   Q19. Do you need to know how to calculate gradients yourself?
//   Q23. What is the function to calculate new weights using a learning rate?
//   Q25. Write pseudocode for the basic steps in each epoch for SGD.
//
// =============================================================================
//
// THEORY: WHAT IS A GRADIENT?
// ───────────────────────────
// A gradient is the SLOPE of the loss function with respect to a weight.
// It tells you: "if I increase this weight slightly, does the loss go up or down?"
//
//   gradient > 0 -> increasing weight INCREASES loss -> decrease the weight
//   gradient < 0 -> increasing weight DECREASES loss -> increase the weight
//   gradient = 0 -> at a minimum (or saddle point)
//
// The gradient is a DIRECTION: it points "uphill." We go OPPOSITE to it (downhill).
//
// THEORY: WHAT IS SGD?
// ────────────────────
// SGD = Stochastic Gradient Descent
// "Stochastic" = random. We randomly sample a mini-batch of data each step.
//
// Vanilla gradient descent: compute gradients on ALL data, then update.
//   - Accurate but SLOW for large datasets.
//
// SGD: compute gradients on a random mini-batch, then update.
//   - Noisy but FAST. The noise actually helps escape local minima!
//
// WHY MINI-BATCHES?
//   1. Full dataset is too large to fit in GPU memory
//   2. Computing gradients on all data every step is too slow
//   3. Noise from small batches helps generalization (acts as regularization)
//   4. Typical batch sizes: 32, 64, 128, 256
//
// THEORY: THE 7 STEPS OF SGD
// ──────────────────────────
//   1. INITIALIZE weights randomly (small random values)
//   2. PREDICT: forward pass on a mini-batch
//   3. COMPUTE LOSS: measure how wrong the predictions are
//   4. COMPUTE GRADIENTS: backpropagation (how to adjust each weight)
//   5. UPDATE WEIGHTS: weight = weight - learning_rate * gradient
//   6. REPEAT steps 2-5 for all mini-batches in the dataset (= 1 epoch)
//   7. STOP when loss is low enough or validation metrics stop improving
//
// PSEUDOCODE FOR ONE EPOCH:
//   for each mini_batch in training_data:
//       predictions = model.forward(mini_batch.inputs)
//       loss = loss_function(predictions, mini_batch.targets)
//       gradients = loss.backward()          // backprop
//       for each weight in model:
//           weight -= learning_rate * gradient
//
// THEORY: WEIGHT INITIALIZATION
// ─────────────────────────────
// Weights are initialized with SMALL RANDOM values.
// Why random? If all weights start the same, all neurons learn the same thing.
// Why small? Large initial weights cause exploding gradients and saturation.
// Common methods:
//   - Uniform random in [-0.5, 0.5] or [-1, 1]
//   - Xavier/Glorot: scale by 1/sqrt(n_inputs)
//   - He initialization: scale by sqrt(2/n_inputs) (for ReLU)
//
// THEORY: WEIGHT UPDATE FUNCTION
// ──────────────────────────────
//   new_weight = old_weight - learning_rate * gradient
//
// This is the core of gradient descent. The learning rate controls step size.
//
// THEORY: WHY NOT ALWAYS USE A HIGH LEARNING RATE?
// ─────────────────────────────────────────────────
// Too high: overshooting! The model jumps PAST the minimum and bounces around.
//   Imagine walking down a valley but taking 100-foot steps — you jump over it.
//   Loss may INCREASE or oscillate wildly.
//
// Too low: very slow convergence. Takes thousands of extra epochs.
//   Like taking 1-millimeter steps to cross a valley.
//
// Just right: smooth, steady decrease in loss.
// Typical starting values: 0.01, 0.001. Reduce over time (learning rate schedule).
//
// THEORY: DO YOU NEED TO CALCULATE GRADIENTS YOURSELF?
// ────────────────────────────────────────────────────
// No! In practice, frameworks (PyTorch, TensorFlow) compute gradients
// AUTOMATICALLY using "autograd" (automatic differentiation).
// But understanding the concept is essential for debugging and intuition.
// That's what this exercise is for — after this, you can trust the framework.
//
// =============================================================================

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

// ── Part A: Weight Initialization ────────────────────────────────────────────

// TODO Part A: Initialize weights with small random values
// Use Xavier initialization: random value in range [-1/sqrt(n), 1/sqrt(n)]
// where n = number of inputs to the neuron
double initWeight(int n_inputs) {
    // YOUR CODE HERE
    // 1. Compute scale = 1.0 / sqrt(n_inputs)
    // 2. Return random value in range [-scale, +scale]
    // Hint: ((double)rand() / RAND_MAX) gives a value in [0, 1]
    //       Multiply by 2*scale and subtract scale to get [-scale, +scale]

    return 0.0; // placeholder
}

// ── Part B: Gradient Computation ─────────────────────────────────────────────

// A simple quadratic loss: L(w) = (w - 3)^2
// The minimum is at w = 3 (where loss = 0).
// The gradient: dL/dw = 2*(w - 3)
//
// TODO Part B: Compute the gradient of (w - target)^2
double computeGradient(double w, double target) {
    // YOUR CODE HERE
    // gradient = 2 * (w - target)

    return 0.0; // placeholder
}

// ── Part C: Weight Update ────────────────────────────────────────────────────

// TODO Part C: Implement the weight update rule
// Formula: new_weight = old_weight - learning_rate * gradient
double updateWeight(double weight, double gradient, double learning_rate) {
    // YOUR CODE HERE

    return weight; // placeholder
}

// ── Part D: Full SGD Loop ────────────────────────────────────────────────────

// TODO Part D: Implement SGD to find the minimum of L(w) = (w - 3)^2
// This simulates ALL 7 steps of SGD on the simplest possible problem.
void runSGD(double initial_weight, double learning_rate, int epochs) {
    double w = initial_weight;  // Step 1: Initialize

    cout << "Initial weight: " << w << ", Learning rate: " << learning_rate << endl;

    for (int epoch = 0; epoch < epochs; epoch++) {
        // Step 2: "Predict" (here, just the weight itself)
        // Step 3: Compute loss
        double loss = (w - 3.0) * (w - 3.0);

        // Step 4: Compute gradient
        double grad = computeGradient(w, 3.0);

        // Step 5: Update weight
        w = updateWeight(w, grad, learning_rate);

        // Print progress
        if (epoch < 10 || epoch % 10 == 0) {
            printf("  Epoch %3d: w=%.6f, loss=%.6f, grad=%.6f\n",
                   epoch, w, loss, grad);
        }
    }

    cout << "  Final weight: " << w << " (target: 3.0)" << endl;
    cout << "  Final loss: " << (w - 3.0) * (w - 3.0) << endl << endl;
}

// ── Part E: Learning Rate Comparison ─────────────────────────────────────────

void learningRateDemo() {
    cout << "\n=== Learning Rate Comparison ===" << endl;

    // Too low — converges slowly
    cout << "\n--- Learning rate = 0.01 (too low) ---" << endl;
    runSGD(0.0, 0.01, 50);

    // Just right — smooth convergence
    cout << "--- Learning rate = 0.1 (good) ---" << endl;
    runSGD(0.0, 0.1, 50);

    // Too high — overshooting!
    cout << "--- Learning rate = 1.1 (too high!) ---" << endl;
    runSGD(0.0, 1.1, 20);

    // Observe: lr=1.1 causes the weight to BOUNCE past the target!
    // The loss INCREASES instead of decreasing. This is "divergence."
}

// =============================================================================

int main() {
    srand(42);

    // Part A: Show weight initialization
    cout << "=== Weight Initialization ===" << endl;
    cout << "Xavier init for 2 inputs (scale = 1/sqrt(2) = 0.707):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "  w" << i << " = " << initWeight(2) << endl;
    }
    cout << "\nXavier init for 100 inputs (scale = 1/sqrt(100) = 0.1):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "  w" << i << " = " << initWeight(100) << endl;
    }

    // Part D & E: Run SGD with different learning rates
    learningRateDemo();

    // Summary
    cout << "=== The 7 Steps of SGD ===" << endl;
    cout << "1. Initialize weights (small random values)" << endl;
    cout << "2. Forward pass: compute predictions" << endl;
    cout << "3. Compute loss" << endl;
    cout << "4. Compute gradients (backprop)" << endl;
    cout << "5. Update weights: w = w - lr * gradient" << endl;
    cout << "6. Repeat 2-5 for each mini-batch (= 1 epoch)" << endl;
    cout << "7. Stop when done (loss converged, val metrics good)" << endl;

    cout << "\n=== SGD Epoch Pseudocode ===" << endl;
    cout << "for each epoch:" << endl;
    cout << "    for each mini_batch in shuffle(training_data):" << endl;
    cout << "        predictions = model.forward(mini_batch.inputs)" << endl;
    cout << "        loss = loss_function(predictions, mini_batch.targets)" << endl;
    cout << "        gradients = loss.backward()" << endl;
    cout << "        for each weight in model.parameters():" << endl;
    cout << "            weight -= learning_rate * weight.gradient" << endl;
    cout << "        zero_gradients()  // reset for next batch!" << endl;

    return 0;
}
