#include<bits/stdc++.h>
using namespace std;
int fact(int n,int dp[])
{
if(n<=1)
return 1;
if(dp[n]!=-1)
return dp[n];
return dp[n]=n*fact(n-1,dp);
}
int main()
{
    int n;
    cout<<" \n enter the number factorial:";
    cin>>n;
    cout<<"\n";
int dp[n+1];
memset(dp,-1,sizeof(dp));
cout<<"the answer is:"<<fact(4,dp);
}