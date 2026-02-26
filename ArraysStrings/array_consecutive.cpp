#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// ============================================================
// APPROACH 1: Brute Force - O(n^3) Time, O(1) Space
// ============================================================
// For every number, linearly search for the next consecutive
// number in the array. Repeat until the streak breaks.
// Three nested levels: pick start × extend streak × search array
int bruteForce(vector<int>& nums) {
    int best = 0;

    for (int num : nums) {
        int current = num;
        int streak = 1;

        // Keep looking for the next number in sequence
        while (true) {
            bool found = false;
            for (int x : nums) {           // O(n) search each time
                if (x == current + 1) {
                    found = true;
                    break;
                }
            }
            if (!found) break;
            current++;
            streak++;
        }
        best = max(best, streak);
    }
    return best;
}

// ============================================================
// APPROACH 2: Sorting - O(n log n) Time, O(1) Space
// ============================================================
// After sorting, consecutive numbers sit next to each other.
// One pass through the sorted array builds all streaks.
int sortingApproach(vector<int>& nums) {
    if (nums.empty()) return 0;

    sort(nums.begin(), nums.end());

    int best = 1, streak = 1;
    for (int i = 1; i < (int)nums.size(); i++) {
        if (nums[i] == nums[i - 1])           // duplicate — skip
            continue;
        if (nums[i] == nums[i - 1] + 1)       // consecutive — extend
            streak++;
        else                                    // gap — reset
            streak = 1;
        best = max(best, streak);
    }
    return best;
}

// ============================================================
// APPROACH 3: HashSet — O(n) Time, O(n) Space  [OPTIMAL]
// ============================================================
// Two key ideas:
//   1. Use a HashSet so "is x in array?" is O(1) instead of O(n).
//   2. Only start counting from the HEAD of a sequence.
//      A number is a head if (num - 1) is NOT in the set.
//
// Each number is visited at most twice (once in the loop,
// once while extending a streak), so total work is O(n).
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());   // O(n)

    int best = 0;

    for (int num : s) {
        // If num-1 exists, num is NOT the start of a sequence — skip it.
        // This single check is what keeps us at O(n).
        if (s.count(num - 1)) continue;

        // num is the START of a sequence — extend forward
        int streak = 1;
        while (s.count(num + streak))
            streak++;
r
        best = max(best, streak);
    }
    return best;
}

int main() {
    vector<int> nums1 = {2, 20, 4, 10, 3, 4, 5};
    vector<int> nums2 = {0, 3, 2, 5, 4, 6, 1, 1};

    cout << "=== Example 1: [2, 20, 4, 10, 3, 4, 5] ===" << endl;
    cout << "Brute Force : " << bruteForce(nums1)           << endl;
    cout << "Sorting     : " << sortingApproach(nums1)      << endl;
    cout << "HashSet     : " << longestConsecutive(nums1)    << endl;

    cout << "\n=== Example 2: [0, 3, 2, 5, 4, 6, 1, 1] ===" << endl;
    cout << "Brute Force : " << bruteForce(nums2)           << endl;
    cout << "Sorting     : " << sortingApproach(nums2)      << endl;
    cout << "HashSet     : " << longestConsecutive(nums2)    << endl;

    return 0;
}
