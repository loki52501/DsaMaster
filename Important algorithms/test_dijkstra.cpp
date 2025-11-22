#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Forward declaration
vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges);

// Include the implementation (we will link or include the file, but for simplicity in this script I'll just include the cpp file if it was a header, but since it's a cpp file, I'll compile them together or just paste the implementation here for testing if I can't link.
// Actually, I'll just assume I can compile them together.
// But wait, the user's file has no main, so I can just include it?
// Including a .cpp file is bad practice but for a quick test script it works.
// However, the user's file might have headers that conflict or missing headers.
// Let's just declare the prototype and compile both.

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i < v.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
}

int main() {
    int start = 0;
    vector<vector<vector<int>>> edges = {
        {{1, 7}},
        {{2, 6}, {3, 20}, {4, 3}},
        {{3, 14}},
        {{4, 2}},
        {},
        {}
    };

    vector<int> expected = {0, 7, 13, 27, 10, -1};
    vector<int> result = dijkstrasAlgorithm(start, edges);

    cout << "Result: ";
    printVector(result);
    cout << "Expected: ";
    printVector(expected);

    if (result == expected) {
        cout << "Test PASSED" << endl;
        return 0;
    } else {
        cout << "Test FAILED" << endl;
        return 1;
    }
}
