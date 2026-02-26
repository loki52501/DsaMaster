// =============================================================================
// Exercise 1: Images and Tensors
// =============================================================================
//
// SELF-CHECK QUESTIONS COVERED:
//   Q1.  How is a grayscale image represented? Color image?
//   Q4.  What is a list comprehension? (C++ equivalent)
//   Q5.  What is a "rank-3 tensor"?
//   Q6.  What is the difference between tensor rank and shape?
//   Q8.  How can you apply a calculation on thousands of numbers at once?
//   Q9.  Create a 3x3 tensor, double it, select bottom-right four.
//   Q10. What is broadcasting?
//   Q26. Create a zip function.
//
// =============================================================================
//
// THEORY: IMAGE REPRESENTATION
// ─────────────────────────────
// A GRAYSCALE image is a 2D grid of pixel values, each in range [0, 255].
//   0 = black, 255 = white, values in between = shades of gray.
//   A 28x28 grayscale image = 784 numbers arranged in 28 rows x 28 cols.
//   This is a rank-2 tensor (a matrix) with shape [28, 28].
//
// A COLOR (RGB) image adds a third dimension: 3 color channels (Red, Green, Blue).
//   Each channel is a 2D grid of values [0, 255].
//   A 28x28 color image = shape [3, 28, 28] or [28, 28, 3].
//   This is a rank-3 tensor.
//
// THEORY: TENSORS
// ───────────────
// A tensor is just a multi-dimensional array of numbers.
//   Rank-0: scalar         (e.g. 5)
//   Rank-1: vector         (e.g. [1, 2, 3])          shape: [3]
//   Rank-2: matrix         (e.g. [[1,2],[3,4]])       shape: [2, 2]
//   Rank-3: 3D array       (e.g. a color image)       shape: [3, 28, 28]
//
// RANK = number of dimensions = number of elements in the shape.
//   Shape [3, 28, 28] -> rank = 3 (three numbers in the shape).
//   Shape [28, 28]    -> rank = 2.
//   Shape [784]       -> rank = 1.
//
// THEORY: BROADCASTING
// ────────────────────
// Broadcasting lets you do math between tensors of different shapes.
// Example: adding a scalar to every element of a matrix.
//   matrix[3][3] + 10  -->  adds 10 to ALL 9 elements.
// Example: adding a vector to each row of a matrix.
//   matrix[3][3] + vector[3]  -->  adds vector to each row.
// The smaller tensor is "broadcast" (stretched) to match the larger one.
// This avoids writing explicit loops — it's faster and cleaner.
//
// THEORY: VECTORIZED OPERATIONS
// ─────────────────────────────
// Instead of looping through elements one by one, vectorized operations
// apply a function to an entire array at once. Libraries like NumPy (Python)
// or SIMD instructions (C++) do this under the hood, achieving massive
// speedups — often 100x-1000x faster than a Python for-loop.
//
// In C++, we simulate this by operating on arrays in tight loops that the
// compiler can auto-vectorize. In Python, you'd use NumPy.
//
// THEORY: LIST COMPREHENSION & ZIP
// ────────────────────────────────
// A list comprehension (Python) builds a list with a one-liner:
//   [x*2 for x in range(10) if x % 2 == 1]  -> [2, 6, 10, 14, 18]
//   This selects odd numbers and doubles them.
//
// In C++, the equivalent uses a loop or std::transform + std::copy_if.
//
// A zip function pairs elements from two sequences:
//   zip([1,2,3], "abc") -> [(1,'a'), (2,'b'), (3,'c')]
// The result is a list of tuples (pairs).
//
// =============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <utility>   // for std::pair
#include <string>
using namespace std;

// ── Part A: Grayscale Image ──────────────────────────────────────────────────

// A 5x5 "image" of the digit 1 (0=black, 255=white)
// Visualize: the 1s (high values) form a vertical line
const int SMALL_IMG[5][5] = {
    {  0,   0, 200,   0,   0},
    {  0,   0, 200,   0,   0},
    {  0,   0, 200,   0,   0},
    {  0,   0, 200,   0,   0},
    {  0,   0, 200,   0,   0},
};

// TODO Part A: Print the image as a grid of numbers
// Then print it "visually" using '#' for values > 100 and '.' for values <= 100
void printImage() {
    cout << "=== Grayscale Image (numbers) ===" << endl;
    // YOUR CODE HERE: print SMALL_IMG as a grid of numbers

    cout << "\n=== Visual representation ===" << endl;
    // YOUR CODE HERE: print '#' for values > 100, '.' otherwise
}

// ── Part B: Tensors — Rank and Shape ─────────────────────────────────────────

// TODO Part B: Create a 3x3 matrix with values 1-9, double it, extract bottom-right 2x2
// This directly answers Q9.
void tensorOperations() {
    cout << "\n=== Tensor Operations ===" << endl;

    // Step 1: Create a 3x3 "tensor" (rank-2) with values 1 through 9
    int tensor[3][3];
    // YOUR CODE HERE: fill tensor with 1,2,3 / 4,5,6 / 7,8,9

    // Step 2: Double every element (vectorized-style — one loop, not element by element)
    // YOUR CODE HERE

    // Step 3: Print the doubled tensor
    cout << "Doubled 3x3 tensor:" << endl;
    // YOUR CODE HERE

    // Step 4: Extract and print the bottom-right 2x2 submatrix
    // (rows 1-2, cols 1-2 of the doubled tensor)
    cout << "\nBottom-right 2x2:" << endl;
    // YOUR CODE HERE
    // Expected: 10 12
    //           14 16  (was 5,6,7,8 -> doubled to 10,12,14,16)

    // Q6 answer: print rank and shape
    cout << "\nThis tensor has:" << endl;
    cout << "  Shape: [3, 3]" << endl;
    cout << "  Rank:  2 (= number of dimensions in the shape)" << endl;
}

// ── Part C: Broadcasting ─────────────────────────────────────────────────────

// TODO Part C: Demonstrate broadcasting
void broadcastDemo() {
    cout << "\n=== Broadcasting ===" << endl;

    // A 3x3 matrix
    double matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Broadcasting a SCALAR: add 10 to every element
    cout << "Matrix + 10 (scalar broadcast):" << endl;
    // YOUR CODE HERE: add 10 to each element and print the result
    // The scalar 10 is "broadcast" to match the shape [3,3]

    // Broadcasting a VECTOR: add [100, 200, 300] to each row
    double row_vec[3] = {100, 200, 300};
    cout << "\nMatrix + [100,200,300] (vector broadcast):" << endl;
    // YOUR CODE HERE: add row_vec[j] to matrix[i][j] for each i,j and print
    // The vector [3] is "broadcast" across rows to match [3,3]
}

// ── Part D: Vectorized vs Loop Speed ─────────────────────────────────────────

// TODO Part D: Compare loop vs "vectorized" operation speed
void speedComparison() {
    cout << "\n=== Vectorized Speed Comparison ===" << endl;

    const int N = 10000000;  // 10 million elements
    vector<double> data(N, 1.0);
    vector<double> result(N);

    // Approach 1: Element-by-element with function call overhead
    auto start1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        result[i] = data[i] * 2.0 + 1.0;  // simple vectorizable operation
    }
    auto end1 = chrono::high_resolution_clock::now();
    double ms1 = chrono::duration<double, milli>(end1 - start1).count();

    // In Python, a raw for-loop over 10M items takes ~2000ms.
    // NumPy vectorized: ~15ms. That's >100x faster!
    // In C++, the compiler auto-vectorizes tight loops, so both are fast.
    // But the CONCEPT is the same: avoid per-element overhead.

    cout << "Processed " << N << " elements in " << ms1 << " ms" << endl;
    cout << "(In Python, NumPy vectorization is 100x+ faster than a for-loop)" << endl;
}

// ── Part E: List Comprehension (C++ equivalent) ──────────────────────────────

// TODO Part E: Implement the equivalent of Python's list comprehension
// Python: [x*2 for x in numbers if x % 2 == 1]
// This selects odd numbers from a list and doubles them.
vector<int> selectOddAndDouble(const vector<int>& numbers) {
    vector<int> result;
    // YOUR CODE HERE
    // Loop through numbers, if odd (x%2==1), push x*2 into result
    return result;
}

// ── Part F: Zip Function ─────────────────────────────────────────────────────

// TODO Part F: Create a zip function
// Given [1,2,3,4] and "abcd", return [(1,'a'), (2,'b'), (3,'c'), (4,'d')]
// The output is a list of pairs (tuples) — one element from each input.
vector<pair<int, char>> zipFunction(const vector<int>& nums, const string& chars) {
    vector<pair<int, char>> result;
    // YOUR CODE HERE
    // Loop through both sequences simultaneously, pairing elements
    return result;
}

// ── Part G: Color Image (Rank-3 Tensor) ──────────────────────────────────────

void colorImageDemo() {
    cout << "\n=== Color Image (Rank-3 Tensor) ===" << endl;

    // A tiny 2x2 color image: shape [3, 2, 2] — 3 channels (R,G,B), 2 rows, 2 cols
    int color_img[3][2][2] = {
        {{255, 0},  {0, 255}},    // Red channel
        {{0, 255},  {0, 0}},      // Green channel
        {{0, 0},    {255, 0}},    // Blue channel
    };

    // Top-left pixel: R=255, G=0, B=0 -> pure red
    // Top-right pixel: R=0, G=255, B=0 -> pure green
    // Bottom-left pixel: R=0, G=0, B=255 -> pure blue
    // Bottom-right pixel: R=255, G=0, B=0 -> pure red

    cout << "Shape: [3, 2, 2]  (channels, height, width)" << endl;
    cout << "Rank: 3  (three dimensions)" << endl;
    cout << "\nPixel colors:" << endl;
    string names[2][2] = {{"red", "green"}, {"blue", "red"}};
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 2; c++) {
            cout << "  [" << r << "," << c << "] R="
                 << color_img[0][r][c] << " G="
                 << color_img[1][r][c] << " B="
                 << color_img[2][r][c] << " -> " << names[r][c] << endl;
        }
    }
}

// =============================================================================

int main() {
    printImage();
    tensorOperations();
    broadcastDemo();
    speedComparison();

    // Test list comprehension
    cout << "\n=== List Comprehension ===" << endl;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> result = selectOddAndDouble(nums);
    cout << "Odd numbers doubled: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    cout << "Expected: 2 6 10 14 18" << endl;

    // Test zip function
    cout << "\n=== Zip Function ===" << endl;
    vector<int> numbers = {1, 2, 3, 4};
    string letters = "abcd";
    auto zipped = zipFunction(numbers, letters);
    cout << "Zipped: ";
    for (auto& p : zipped) cout << "(" << p.first << ",'" << p.second << "') ";
    cout << endl;
    cout << "Expected: (1,'a') (2,'b') (3,'c') (4,'d')" << endl;
    cout << "These are PAIRS (tuples) — a fixed-size grouping of values." << endl;

    colorImageDemo();

    return 0;
}
