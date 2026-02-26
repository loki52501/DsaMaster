// =============================================================================
// Exercise 7: Backpropagation and Training Loop
// =============================================================================
//
// SELF-CHECK QUESTIONS COVERED:
//   Q24. What does the DataLoader class do?
//   Q30. What does the `backward` method do?
//   Q31. Why do we have to zero the gradients?
//   Q32. What information do we have to pass to Learner?
//   Q33. Show pseudocode for the basic steps of a training loop.
//
// =============================================================================
//
// THEORY: THE BACKWARD METHOD
// ───────────────────────────
// In PyTorch: loss.backward() computes the gradient of the loss with respect
// to EVERY parameter (weight and bias) in the network.
//
// It uses the CHAIN RULE to propagate gradients backward:
//   Output layer -> Hidden layer -> Input layer
//
// For each weight w, backward() computes dLoss/dw (how much changing w
// would change the loss). These gradients are STORED in each parameter.
//
// THEORY: WHY ZERO THE GRADIENTS?
// ───────────────────────────────
// PyTorch ACCUMULATES gradients by default! Each call to backward() ADDS
// to the existing gradients. If you don't zero them, you get the sum of
// gradients from multiple forward passes, which is WRONG.
//
// Correct pattern:
//   optimizer.zero_grad()   // reset gradients to 0
//   loss = model(data)      // forward pass
//   loss.backward()         // compute gradients
//   optimizer.step()        // update weights
//
// Why does PyTorch accumulate? It's useful for:
//   - Gradient accumulation across mini-batches (simulate larger batches)
//   - RNNs where you sum gradients over time steps
// But for standard training, you must zero them each iteration.
//
// THEORY: DATALOADER
// ──────────────────
// A DataLoader wraps a dataset and provides:
//   - Automatic batching: groups samples into mini-batches
//   - Shuffling: randomizes order each epoch (prevents overfitting)
//   - Parallel loading: loads data in background while GPU trains
//
// Usage:
//   loader = DataLoader(dataset, batch_size=64, shuffle=True)
//   for batch_inputs, batch_targets in loader:
//       predictions = model(batch_inputs)
//       loss = loss_fn(predictions, batch_targets)
//       ...
//
// THEORY: LEARNER (fastai)
// ────────────────────────
// A Learner wraps everything needed for training:
//   learner = Learner(dls, model, loss_func, optimizer, metrics)
//
// Required information:
//   1. dls (DataLoaders): training and validation data loaders
//   2. model: the neural network architecture
//   3. loss_func: the loss function (e.g., cross_entropy)
//   4. optimizer: how to update weights (e.g., SGD, Adam)
//   5. metrics: what to report (e.g., accuracy) — for monitoring, not training
//
// THEORY: COMPLETE TRAINING LOOP PSEUDOCODE
// ─────────────────────────────────────────
//   model = create_model()
//   optimizer = SGD(model.parameters(), lr=0.01)
//   loss_fn = MSELoss()
//
//   for epoch in range(n_epochs):
//       # Training phase
//       model.train()
//       for inputs, targets in train_loader:
//           optimizer.zero_grad()          # 1. Zero gradients
//           predictions = model(inputs)     # 2. Forward pass
//           loss = loss_fn(predictions, targets)  # 3. Compute loss
//           loss.backward()                 # 4. Compute gradients
//           optimizer.step()                # 5. Update weights
//
//       # Validation phase
//       model.eval()
//       val_loss = 0
//       for inputs, targets in valid_loader:
//           predictions = model(inputs)
//           val_loss += loss_fn(predictions, targets)
//       print(f"Epoch {epoch}: val_loss = {val_loss}")
//
// =============================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

double sigmoid(double x) { return 1.0 / (1.0 + exp(-x)); }

// ── Part A: Simple DataLoader ────────────────────────────────────────────────

struct Sample {
    double x1, x2;
    double target;
};

// TODO Part A: Implement a simple DataLoader
// A DataLoader takes a dataset and returns mini-batches.
// It should:
//   1. Optionally shuffle the data
//   2. Split data into chunks of batch_size
//   3. Return each batch one at a time
class DataLoader {
public:
    vector<Sample> data;
    int batch_size;
    bool shuffle;
    int current_pos;

    DataLoader(const vector<Sample>& dataset, int bs, bool shuf = true)
        : data(dataset), batch_size(bs), shuffle(shuf), current_pos(0) {}

    // Call this at the start of each epoch
    void reset() {
        current_pos = 0;
        if (shuffle) {
            // YOUR CODE HERE: shuffle the data vector
            // Hint: use std::random_shuffle or std::shuffle
        }
    }

    // Returns true if there are more batches
    bool hasNext() {
        return current_pos < (int)data.size();
    }

    // TODO: Return the next batch of samples
    vector<Sample> nextBatch() {
        vector<Sample> batch;
        // YOUR CODE HERE
        // 1. Take up to batch_size samples starting from current_pos
        // 2. Advance current_pos
        // 3. Return the batch

        return batch;
    }
};

// ── Part B: Neuron with Gradient Storage ─────────────────────────────────────

struct Neuron {
    double w1, w2, bias;

    // Gradients — accumulated during backward, applied during update
    double grad_w1, grad_w2, grad_bias;

    void init() {
        w1 = 0.5; w2 = 0.5; bias = -0.2;
        zeroGrad();
    }

    // TODO Part B1: Zero all gradients
    // WHY: PyTorch accumulates gradients. We must reset before each backward.
    void zeroGrad() {
        // YOUR CODE HERE
        // Set grad_w1, grad_w2, grad_bias to 0
    }

    double forward(double x1, double x2) {
        return sigmoid(w1 * x1 + w2 * x2 + bias);
    }

    // TODO Part B2: Backward pass — compute and ACCUMULATE gradients
    // This is what loss.backward() does in PyTorch
    void backward(double x1, double x2, double predicted, double target) {
        // YOUR CODE HERE
        // Chain rule:
        //   dLoss/dPred = 2 * (predicted - target)
        //   dPred/dZ = predicted * (1 - predicted)    [sigmoid derivative]
        //   delta = dLoss/dPred * dPred/dZ
        //
        //   grad_w1 += delta * x1     (ACCUMULATE, don't overwrite!)
        //   grad_w2 += delta * x2
        //   grad_bias += delta
    }

    // TODO Part B3: Update weights using accumulated gradients
    // This is what optimizer.step() does in PyTorch
    void step(double learning_rate) {
        // YOUR CODE HERE
        // w1 -= learning_rate * grad_w1
        // w2 -= learning_rate * grad_w2
        // bias -= learning_rate * grad_bias
    }
};

// ── Part C: Complete Training Loop ───────────────────────────────────────────

void train() {
    cout << "=== Complete Training Loop (AND gate) ===" << endl;

    // Dataset
    vector<Sample> train_data = {{0,0,0}, {0,1,0}, {1,0,0}, {1,1,1}};
    // In real ML, you'd have separate validation data:
    vector<Sample> valid_data = {{0,0,0}, {0,1,0}, {1,0,0}, {1,1,1}};

    // Create DataLoader (batch_size=2, with shuffling)
    DataLoader train_loader(train_data, 2, true);
    DataLoader valid_loader(valid_data, 4, false);  // no shuffle for validation

    // Model
    Neuron model;
    model.init();

    double learning_rate = 1.0;
    int n_epochs = 5000;

    cout << "Architecture: 1 neuron (2 inputs)" << endl;
    cout << "Batch size: 2, Learning rate: " << learning_rate << endl << endl;

    // Training loop — matches the pseudocode exactly
    for (int epoch = 0; epoch < n_epochs; epoch++) {

        // ── Training phase ──
        train_loader.reset();
        double train_loss = 0.0;
        int train_count = 0;

        while (train_loader.hasNext()) {
            vector<Sample> batch = train_loader.nextBatch();

            model.zeroGrad();  // Step 1: Zero gradients!

            for (auto& s : batch) {
                double pred = model.forward(s.x1, s.x2);       // Step 2: Forward
                train_loss += (pred - s.target) * (pred - s.target); // Step 3: Loss
                model.backward(s.x1, s.x2, pred, s.target);    // Step 4: Backward
                train_count++;
            }

            model.step(learning_rate);  // Step 5: Update weights
        }

        // ── Validation phase (every 500 epochs) ──
        if (epoch % 500 == 0) {
            valid_loader.reset();
            double val_loss = 0.0;
            int correct = 0;
            int val_count = 0;

            while (valid_loader.hasNext()) {
                vector<Sample> batch = valid_loader.nextBatch();
                for (auto& s : batch) {
                    double pred = model.forward(s.x1, s.x2);
                    val_loss += (pred - s.target) * (pred - s.target);
                    if ((pred > 0.5) == (s.target > 0.5)) correct++;
                    val_count++;
                }
            }

            printf("Epoch %4d | Train loss: %.4f | Val loss: %.4f | Val acc: %d/%d\n",
                   epoch, train_loss / train_count, val_loss / val_count, correct, val_count);
        }
    }

    // Final test
    cout << "\n=== Final Results ===" << endl;
    for (auto& s : valid_data) {
        double pred = model.forward(s.x1, s.x2);
        printf("  (%.0f, %.0f) -> %.4f (expected: %.0f) %s\n",
               s.x1, s.x2, pred, s.target,
               ((pred > 0.5) == (s.target > 0.5)) ? "OK" : "WRONG");
    }
}

// ── Part D: Demonstrate WHY We Zero Gradients ────────────────────────────────

void zeroGradDemo() {
    cout << "\n=== Why Zero Gradients? ===" << endl;

    Neuron n;
    n.init();

    // Forward + backward on sample (1, 1, target=1)
    double pred = n.forward(1, 1);
    n.backward(1, 1, pred, 1);
    cout << "After 1st backward: grad_w1=" << n.grad_w1 << endl;

    // Another forward + backward WITHOUT zeroing (BUG!)
    pred = n.forward(0, 1);
    n.backward(0, 1, pred, 0);
    cout << "After 2nd backward (NO zero): grad_w1=" << n.grad_w1
         << " (ACCUMULATED - wrong!)" << endl;

    // Correct: zero first, then backward
    n.zeroGrad();
    pred = n.forward(0, 1);
    n.backward(0, 1, pred, 0);
    cout << "After zero + 2nd backward: grad_w1=" << n.grad_w1
         << " (correct!)" << endl;

    cout << "\nWithout zeroing, gradients from previous batches leak in!" << endl;
}

// =============================================================================

int main() {
    srand(42);

    zeroGradDemo();
    cout << endl;
    train();

    cout << "\n=== Training Loop Pseudocode ===" << endl;
    cout << "for epoch in range(n_epochs):" << endl;
    cout << "    for inputs, targets in train_loader:  # DataLoader provides batches" << endl;
    cout << "        optimizer.zero_grad()              # zero accumulated gradients" << endl;
    cout << "        predictions = model(inputs)         # forward pass" << endl;
    cout << "        loss = loss_fn(predictions, targets) # compute loss" << endl;
    cout << "        loss.backward()                      # compute gradients" << endl;
    cout << "        optimizer.step()                     # update weights" << endl;
    cout << "    validate(model, valid_loader)            # check generalization" << endl;

    cout << "\n=== Learner (fastai) needs ===" << endl;
    cout << "Learner(dls, model, loss_func, opt_func, metrics)" << endl;
    cout << "  dls:       DataLoaders (train + valid)" << endl;
    cout << "  model:     the neural network" << endl;
    cout << "  loss_func: e.g. cross_entropy" << endl;
    cout << "  opt_func:  e.g. SGD" << endl;
    cout << "  metrics:   e.g. accuracy (for reporting, NOT training)" << endl;

    return 0;
}
