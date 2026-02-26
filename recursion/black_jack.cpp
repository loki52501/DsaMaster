#include <bits/stdc++.h>
using namespace std;
float helper (int currentHand, int target, unordered_map<int, float>& memo) {
if (memo.find(currentHand) != memo.end()) return memo [currentHand];
if (currentHand > target) return 1;
if ((currentHand + 4) >= target) return 0;
float totalProb = 0;
for (int i = 1 i <= 10 i++) {
totalProb += 0.1*helper(currentHand + i, target, memo);
}
memo [currentHand] = totalProb;
return totalProb;
}
float blackjackProbability(int target, int startingHand) {
unordered_map<int, float> mp;
float ans = helper (startingHand, target, mp);
return round(ans * 1000.0) / 1000.0;;
}