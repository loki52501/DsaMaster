#include <iostream>
#include <vector>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2) {
    int n1 = str1.length();
    int n2 = str2.length();
    
    // dp[i][j] will be the length of LCS of str1[0..j-1] and str2[0..i-1]
    vector<vector<int>> dp(n2 + 1, vector<int>(n1 + 1, 0));
    
    for (int i = 1; i <= n2; i++) {
        for (int j = 1; j <= n1; j++) {
            if (str2[i - 1] == str1[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // Reconstruct the LCS by backtracking from the last cell
    vector<char> lcs;
    int i = n2, j = n1;
    while (i > 0 && j > 0) {
        if (str2[i - 1] == str1[j - 1]) {
            lcs.insert(lcs.begin(), str1[j - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    cout << "Length of LCS: " << dp[n2][n1] << "\n";
    
    return lcs;
}
