// =============================================================================
// Exercise 2: Pixel Similarity Classifier
// =============================================================================
//
// SELF-CHECK QUESTIONS COVERED:
//   Q2. How is the MNIST_SAMPLE dataset structured? Why?
//   Q3. How does "pixel similarity" classification work?
//   Q7. What are RMSE and L1 norm?
//
// =============================================================================
//
// THEORY: MNIST DATASET STRUCTURE
// ────────────────────────────────
// The MNIST_SAMPLE dataset is organized as:
//
//   MNIST_SAMPLE/
//     train/                  <- training images
//       3/                    <- all images of digit "3"
//         img_0001.png
//         img_0002.png
//         ...
//       7/                    <- all images of digit "7"
//         img_0001.png
//         ...
//     valid/                  <- validation images (held-out for testing)
//       3/
//         ...
//       7/
//         ...
//
// WHY this structure?
//   - Folders act as LABELS: the folder name IS the digit class.
//   - train/ vs valid/ split prevents overfitting — we test on data
//     the model has never seen during training.
//   - Each image is 28x28 grayscale (784 pixels, values 0-255).
//
// THEORY: PIXEL SIMILARITY APPROACH
// ──────────────────────────────────
// The simplest "classifier" — no learning at all!
//
// Step 1: Compute the AVERAGE image of each digit class.
//         Average all "3" images pixel-by-pixel -> "ideal 3".
//         Average all "7" images pixel-by-pixel -> "ideal 7".
//
// Step 2: To classify a new image, compute its DISTANCE to each ideal.
//         If it's closer to the "ideal 3", classify as 3.
//         If it's closer to the "ideal 7", classify as 7.
//
// Step 3: "Distance" can be measured as L1 or RMSE.
//
// THEORY: L1 NORM AND RMSE
// ────────────────────────
// L1 (Mean Absolute Error):
//   L1 = (1/n) * sum(|predicted[i] - actual[i]|)
//   Just the average of absolute differences.
//
// RMSE (Root Mean Squared Error):
//   RMSE = sqrt((1/n) * sum((predicted[i] - actual[i])^2))
//   Squares the differences first, so bigger errors are penalized more.
//
// =============================================================================

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int IMG_SIZE = 5;  // Using 5x5 "images" for simplicity (real MNIST = 28x28)

// Simulated "digit images" — in real MNIST these would be 28x28 pixel arrays
// Digit "1": vertical line in the middle
const double digit_1_samples[3][IMG_SIZE][IMG_SIZE] = {
    // Sample 1
    {{ 0,  0,200,  0,  0},
     { 0,  0,220,  0,  0},
     { 0,  0,210,  0,  0},
     { 0,  0,200,  0,  0},
     { 0,  0,230,  0,  0}},
    // Sample 2
    {{ 0,  0,180,  0,  0},
     { 0,  0,200, 10,  0},
     { 0,  0,190,  0,  0},
     { 0, 10,210,  0,  0},
     { 0,  0,200,  0,  0}},
    // Sample 3
    {{ 0, 10,210,  0,  0},
     { 0,  0,200,  0,  0},
     { 0,  0,205, 10,  0},
     { 0,  0,195,  0,  0},
     { 0,  0,220, 10,  0}},
};

// Digit "0": a ring shape
const double digit_0_samples[3][IMG_SIZE][IMG_SIZE] = {
    // Sample 1
    {{ 0,200,200,200,  0},
     {200,  0,  0,  0,200},
     {200,  0,  0,  0,200},
     {200,  0,  0,  0,200},
     { 0,200,200,200,  0}},
    // Sample 2
    {{ 0,180,210,190,  0},
     {190,  0, 10,  0,210},
     {200, 10,  0, 10,190},
     {210,  0, 10,  0,200},
     { 0,210,200,180,  0}},
    // Sample 3
    {{ 0,210,190,200,  0},
     {200,  0,  0,  0,190},
     {190,  0,  0,  0,210},
     {200,  0,  0,  0,200},
     { 0,190,210,200,  0}},
};

// ── Part A: Compute the "ideal" (average) image for a digit class ────────────

// TODO Part A: Average multiple images pixel by pixel
// For each pixel position, compute the mean value across all samples.
void computeAverageImage(const double samples[][IMG_SIZE][IMG_SIZE],
                         int num_samples,
                         double avg[IMG_SIZE][IMG_SIZE]) {
    // YOUR CODE HERE
    // For each pixel [r][c]:
    //   sum up samples[0][r][c] + samples[1][r][c] + ... + samples[n-1][r][c]
    //   divide by num_samples
    //   store in avg[r][c]
}

// ── Part B: Distance Metrics ─────────────────────────────────────────────────

// TODO Part B1: Implement L1 distance (Mean Absolute Error)
// Formula: L1 = (1/n) * sum(|a[i] - b[i]|)
double l1Distance(const double a[IMG_SIZE][IMG_SIZE],
                  const double b[IMG_SIZE][IMG_SIZE]) {
    // YOUR CODE HERE
    // Sum up absolute differences of every pixel, then divide by total pixels

    return 0.0; // placeholder
}

// TODO Part B2: Implement RMSE distance (Root Mean Squared Error)
// Formula: RMSE = sqrt((1/n) * sum((a[i] - b[i])^2))
double rmseDistance(const double a[IMG_SIZE][IMG_SIZE],
                    const double b[IMG_SIZE][IMG_SIZE]) {
    // YOUR CODE HERE
    // Sum up squared differences, divide by total pixels, take sqrt

    return 0.0; // placeholder
}

// ── Part C: Classify ─────────────────────────────────────────────────────────

// TODO Part C: Classify a test image as "0" or "1" using pixel similarity
// Compare the test image to both ideals, return the class with smaller distance
int classify(const double test[IMG_SIZE][IMG_SIZE],
             const double ideal_0[IMG_SIZE][IMG_SIZE],
             const double ideal_1[IMG_SIZE][IMG_SIZE]) {
    // YOUR CODE HERE
    // 1. Compute distance from test to ideal_0
    // 2. Compute distance from test to ideal_1
    // 3. Return 0 if closer to ideal_0, else 1

    return -1; // placeholder
}

// =============================================================================

int main() {
    cout << "=== Pixel Similarity Classifier ===" << endl << endl;

    // Step 1: Compute average images
    double avg_1[IMG_SIZE][IMG_SIZE] = {};
    double avg_0[IMG_SIZE][IMG_SIZE] = {};

    computeAverageImage(digit_1_samples, 3, avg_1);
    computeAverageImage(digit_0_samples, 3, avg_0);

    // Print average images
    cout << "Average image of '1':" << endl;
    for (int r = 0; r < IMG_SIZE; r++) {
        for (int c = 0; c < IMG_SIZE; c++)
            printf("%6.1f ", avg_1[r][c]);
        cout << endl;
    }

    cout << "\nAverage image of '0':" << endl;
    for (int r = 0; r < IMG_SIZE; r++) {
        for (int c = 0; c < IMG_SIZE; c++)
            printf("%6.1f ", avg_0[r][c]);
        cout << endl;
    }

    // Step 2: Test with a new image
    // This looks like a "1" (vertical line)
    double test_img[IMG_SIZE][IMG_SIZE] = {
        { 0,  0,190,  0,  0},
        { 0,  0,200,  0,  0},
        { 0,  0,195,  0,  0},
        { 0,  0,205,  0,  0},
        { 0,  0,210,  0,  0},
    };

    cout << "\n--- Test image ---" << endl;
    for (int r = 0; r < IMG_SIZE; r++) {
        for (int c = 0; c < IMG_SIZE; c++)
            printf("%6.1f ", test_img[r][c]);
        cout << endl;
    }

    // Step 3: Measure distances
    double dist_to_1_l1   = l1Distance(test_img, avg_1);
    double dist_to_0_l1   = l1Distance(test_img, avg_0);
    double dist_to_1_rmse = rmseDistance(test_img, avg_1);
    double dist_to_0_rmse = rmseDistance(test_img, avg_0);

    cout << "\nDistances:" << endl;
    cout << "  L1   to '1': " << dist_to_1_l1 << endl;
    cout << "  L1   to '0': " << dist_to_0_l1 << endl;
    cout << "  RMSE to '1': " << dist_to_1_rmse << endl;
    cout << "  RMSE to '0': " << dist_to_0_rmse << endl;

    // Step 4: Classify
    int prediction = classify(test_img, avg_0, avg_1);
    cout << "\nPrediction: " << prediction << " (expected: 1)" << endl;

    // OBSERVATIONS:
    // - The test image should be classified as "1" (closer to the ideal 1).
    // - L1 gives the average absolute pixel difference.
    // - RMSE penalizes large differences more because of squaring.
    // - This method WORKS for very distinct digits but fails for similar ones.
    // - It has no learning — it just compares to averages.
    //   Neural networks are much more powerful because they LEARN features.

    return 0;
}
