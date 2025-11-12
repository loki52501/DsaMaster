#include<iostream>
#include<vector>
using namespace std;
int fibo(int n, vector<int>dp)
{
    if(n<=1)
    return 1;
    if(dp[n-1]!=-1 && dp[n-2]!=-1)
 return   dp[n]=dp[n-1]+dp[n-2];
    else
    return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
}
int main()
{
int n=3;
vector<int> dp(n+1,-1);
cout<<fibo(n,dp);
}