
  // Given an array of distinct positive integers representing coin denominations and a
  //single non-negative integer 
  #include<iostream>
  #include<thread>
  #include<future>
  #include<vector>
  #include<thread>
  using namespace std;
  int no_make_change(int n,vector<int>denoms,vector<int>&dp, int i=0)
  {if(n==0)
       return 1;
   if(n<0||denoms.empty()||denoms[i]>n)
   return 0;

   dp[n]=
    
return
  }
 int nmc(int n,vector<int>denoms)
  {
   vector<int>de(n);
   for(int i=0;i<denoms.size();i++)
   {
       for(int j=0;j<n;j++)
       {
              if(denoms[i]<=j)
              {
                     de[i]+=de[i-j];
              }
              
       }
   }
   return de[n-1];
  }
  int main()
  {
       vector<int>dr{1,5};
       vector<int> dp(10);
       cout<<no_make_change(6,dr,dp)<<" no of ways to make changes;";
  }