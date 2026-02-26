#include <iostream>
#include <vector>
using namespace std;

// ============================================================
// APPROACH 1: Brute Force (Recursion) — O(2^n) Time, O(n) Space
// ============================================================
// At each day we have a choice: skip, buy (if not holding), sell (if holding).
// We try ALL combinations recursively → exponential blowup.
int solve(vector<int>& prices, int day, bool holding) {
    if (day >= (int)prices.size()) return 0;

    int skip = solve(prices, day + 1, holding);       // do nothing

    if (holding) {
        int sell = prices[day] + solve(prices, day + 1, false);  // sell
        return max(skip, sell);
    } else {
        int buy = -prices[day] + solve(prices, day + 1, true);   // buy
        return max(skip, buy);
    }
}

int bruteForce(vector<int>& prices) {
    return solve(prices, 0, false);
}

// ============================================================
// APPROACH 2: DP (Bottom-Up) — O(n) Time, O(n) Space
// ============================================================
// The recursion only has n × 2 unique states: (day, holding).
// We fill a table bottom-up instead of recomputing.
//
// dp[i][0] = max profit from day i onward, NOT holding stock
// dp[i][1] = max profit from day i onward, HOLDING stock
//
// Transitions:
//   dp[i][0] = max(dp[i+1][0],  -prices[i] + dp[i+1][1])
//                  skip             buy: spend money, now holding
//
//   dp[i][1] = max(dp[i+1][1],   prices[i] + dp[i+1][0])
//                  skip             sell: gain money, now free
int dpApproach(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--) {
        dp[i][0] = max(dp[i+1][0], -prices[i] + dp[i+1][1]);  // skip or buy
        dp[i][1] = max(dp[i+1][1],  prices[i] + dp[i+1][0]);  // skip or sell
    }
    return dp[0][0];   // start at day 0, not holding
}

// ============================================================
// APPROACH 3: Greedy — O(n) Time, O(1) Space  [OPTIMAL]
// ============================================================
// Key insight: any multi-day profit can be decomposed into
// single-day gains.
//
//   profit(day 1 → day 4) = (p2-p1) + (p3-p2) + (p4-p3)
//
// So just add up every POSITIVE consecutive difference.
// If price goes up tomorrow, we should have bought today.
//
//   prices = [7, 1, 5, 3, 6, 4]
//
//   Day 1→2:  1-7 = -6  (drop, skip)
//   Day 2→3:  5-1 = +4  (rise, TAKE IT ✓)
//   Day 3→4:  3-5 = -2  (drop, skip)
//   Day 4→5:  6-3 = +3  (rise, TAKE IT ✓)
//   Day 5→6:  4-6 = -2  (drop, skip)
//
//   Total = 4 + 3 = 7
int greedy(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < (int)prices.size(); i++) {
        if (prices[i] > prices[i - 1])             // price went up?
            profit += prices[i] - prices[i - 1];   // collect the gain
    }
    return profit;
}

int main() {
    vector<int> p1 = {7, 1, 5, 3, 6, 4};
    vector<int> p2 = {1, 2, 3, 4, 5};

    cout << "=== Example 1: [7, 1, 5, 3, 6, 4] ===" << endl;
    cout << "Brute Force : " << bruteForce(p1)  << endl;
    cout << "DP          : " << dpApproach(p1)  << endl;
    cout << "Greedy      : " << greedy(p1)      << endl;

    cout << "\n=== Example 2: [1, 2, 3, 4, 5] ===" << endl;
    cout << "Brute Force : " << bruteForce(p2)  << endl;
    cout << "DP          : " << dpApproach(p2)  << endl;
    cout << "Greedy      : " << greedy(p2)      << endl;

    return 0;
}
