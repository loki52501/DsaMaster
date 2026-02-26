#include<iostream>
using namespace std;

/*int staircaseTraversal(int height, int maxSteps) {
  if(height==0 || height==1)
  {
    return 1;
  }
  else
  { 
    int sum=0;
    for(int i=1;i<=maxSteps;i++)
    {if(height>=maxSteps)
        sum+=staircaseTraversal(height-i,maxSteps);}
    return sum;
  }
}*/
int staircaseTraversal(int height, int maxSteps) {
  vector<int>dp(height+1,0);
  dp[0]=1;
  dp[1]=1;
 for(int i=2;i<heights;i++)
 for(int j=1;j<maxSteps;j++)
 if((i-j)>=0)
 dp[i]+=dp[i-j];
  return dp[height];
}
/*int dpst(int height, int maxSteps,vector<int>&dp) {
  if(height==0 || height==1)
  {
    return 1;
  }
    else if(dp[height]!=0)
      return dp[height];
  else
  { 
    int sum=0;
    for(int i=1;i<=maxSteps;i++)
    {if(height-i>=0)
        dp[height]+=dpst(height-i,maxSteps,dp);}
    return dp[height];
  
  }
}*/
int main(){
cout<<staircaseTraversal(5,2);
}
