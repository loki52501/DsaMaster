#include <iostream>
#include <vector>
using namespace std;

int lcs(string , string , int ,int ,int );


/*
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

*/

vector<char> longestCommonSubsequence(string str1, string str2) {
  if(str1.size()==0 || str2.size()==0)
  return {};
   int res=lcs(str1,str2,0,0,0);
   cout<<res<<endl;
  
  return {};
}
int lcs(string str1, string str2, int index1,int index2,int count)
{
    if(str1.size()<=index1 || str2.size()<=index2)
    return count;
  cout<<count<<" iteration "<<str1[index1]<<","<<str1.size()<<","<<index1<<" , "<<str2[index2]<<","<<index2<<endl;
    if(str1[index1]==str2[index2])
     return lcs(str1,str2,index1+1,index2+1,count+1);
    int lc=lcs(str1,str2,index1,index2+1,count);
    int rc=lcs(str1,str2,index1+1,index2,count);
return max(lc,rc);
}

int main()
{
    auto s=longestCommonSubsequence("ZXVVYZW", "XKYKZPW");

}