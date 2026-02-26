#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

/*
 * 907. Sum of Subarray Minimums
 * Given an array of integers arr, find the sum of min(b),
 * where b ranges over every (contiguous) subarray of arr.
 * Return the answer modulo 10^9 + 7.
 *
 * Example: arr = [3,1,2,4]
 * Subarrays: [3],[1],[2],[4],[3,1],[1,2],[2,4],[3,1,2],[1,2,4],[3,1,2,4]
 * Minimums:   3,  1,  2,  4,  1,    1,    2,    1,      1,      1
 * Sum = 17
 */

// ==================== APPROACH 1: Brute Force O(n^3) ====================
// For every subarray (i,j), use a third loop to find the minimum.
// Time: O(n^3) | Space: O(1)
int bruteForce(vector<int>& arr) {
    int n = arr.size(), mod = 1e9 + 7;
    long sum = 0;
    for (int i = 0; i < n; i++)           // start of subarray
        for (int j = i; j < n; j++) {     // end of subarray
            int mn = INT_MAX;
            for (int k = i; k <= j; k++)  // find min in subarray [i..j]
                mn = min(mn, arr[k]);
            sum = (sum + mn) % mod;
        }
    return sum;
}

// ==================== APPROACH 2: Optimized Brute Force O(n^2) ====================
// Key insight: when extending subarray [i..j] to [i..j+1],
// the new min is simply min(old_min, arr[j+1]).
// No need for the inner loop — carry the minimum forward.
// Time: O(n^2) | Space: O(1)
int betterBruteForce(vector<int>& arr) {
    int n = arr.size(), mod = 1e9 + 7;
    long sum = 0;
    for (int i = 0; i < n; i++) {
        int mn = arr[i];                  // min starts as the first element
        for (int j = i; j < n; j++) {
            mn = min(mn, arr[j]);         // update min as we extend right
            sum = (sum + mn) % mod;
        }
    }
    return sum;
}

// ==================== APPROACH 3: Monotonic Stack O(n) ====================
// Instead of asking "what is the min of each subarray?",
// flip the question: "for each element, how many subarrays is it the minimum of?"
//
// answer = sum of arr[i] * count[i] for all i
//
// For arr[i] to be the minimum of subarray [L..R]:
//   - every element in [L..R] must be >= arr[i]
//   - L can range from (previous smaller element + 1) to i
//   - R can range from i to (next smaller element - 1)
//
// So count[i] = left[i] * right[i] where:
//   left[i]  = distance to Previous Less-or-Equal Element (# of valid start points)
//   right[i] = distance to Next Strictly Less Element (# of valid end points)
//
// We use strict '<' on one side and '<=' on the other to avoid
// double-counting when there are duplicate values.
//
// Example walkthrough for [3, 1, 2, 4]:
//   arr[0]=3: left=1, right=1 → 3 * 1 * 1 = 3
//   arr[1]=1: left=2, right=3 → 1 * 2 * 3 = 6
//   arr[2]=2: left=1, right=2 → 2 * 1 * 2 = 4
//   arr[3]=4: left=1, right=1 → 4 * 1 * 1 = 4
//   Total = 3 + 6 + 4 + 4 = 17
//
// Time: O(n) | Space: O(n)
int monotonicStack(vector<int>& arr) {
    int n = arr.size(), mod = 1e9 + 7;
    vector<int> left(n), right(n);
    stack<int> s;

    // Pass 1: find left[i] — distance to previous less-or-equal element
    // Stack maintains indices whose values are in increasing order.
    // We pop elements that are strictly greater than arr[i].
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] > arr[i])
            s.pop();
        // If stack is empty, no smaller element exists to the left → left[i] = i + 1
        // Otherwise, the top of stack is the nearest element <= arr[i]
        left[i] = s.empty() ? i + 1 : i - s.top();
        s.push(i);
    }

    while (!s.empty()) s.pop();

    // Pass 2: find right[i] — distance to next strictly less element
    // We pop elements that are greater-or-equal to arr[i].
    // (The asymmetry > vs >= between the two passes handles duplicates)
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        // If stack is empty, no smaller element exists to the right → right[i] = n - i
        // Otherwise, the top of stack is the nearest element < arr[i]
        right[i] = s.empty() ? n - i : s.top() - i;
        s.push(i);
    }

    // Final answer: sum of arr[i] * left[i] * right[i]
    long sum = 0;
    for (int i = 0; i < n; i++)
        sum = (sum + (long)arr[i] % mod * left[i] % mod * right[i]) % mod;
    return sum;
}

int main() {
    vector<int> arr1{3, 1, 2, 4};
    vector<int> arr2{11, 81, 94, 43, 3};

    cout << "arr1 = [3,1,2,4]" << endl;
    cout << "Brute Force O(n^3):    " << bruteForce(arr1) << endl;
    cout << "Better Brute O(n^2):   " << betterBruteForce(arr1) << endl;
    cout << "Monotonic Stack O(n):  " << monotonicStack(arr1) << endl;

    cout << "\narr2 = [11,81,94,43,3]" << endl;
    cout << "Brute Force O(n^3):    " << bruteForce(arr2) << endl;
    cout << "Better Brute O(n^2):   " << betterBruteForce(arr2) << endl;
    cout << "Monotonic Stack O(n):  " << monotonicStack(arr2) << endl;
}
