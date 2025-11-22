#include<iostream>
#include <vector>

using namespace std;

int maxsumhelper(int,int ,vector<int>,vector<vector<int>>& );
vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
    
    int n = array.size();
vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // dp[last+1][index]

    for (int index = n - 1; index >= 0; --index) {
        for (int last = index - 1; last >= -1; --last) {
            int take = INT_MIN;
            if (last == -1 || array[last] < array[index]) {
                take = array[index] + dp[index + 1][index + 1];
            }
            int ntake = dp[last + 1][index + 1];
            dp[last + 1][index] = max(take, ntake);
        }
    }



  for(int i=0;i<array.size();i++)
  for(int j=0;j<array.size();j++)
  {
    cout<<dp[i][j]<<" ";
  }
  return {
    {0},  // Sum of sequence.
    {},   // Elements of the sequence.
  };
}

int maxsumhelper(int last,int index,vector<int> array,vector<vector<int>>&dp)
{
if(index>=array.size())
  return 0;
if( dp[last+1][index]!=-1)
  return dp[last+1][index];
int take=INT_MIN;
  if(last==-1 || array[last]<array[index] )
       take=array[index]+maxsumhelper(index,index+1,array,dp);
  int ntake=maxsumhelper(last,index+1,array,dp);
   return dp[last+1][index]=max(take,ntake);
  // if number at a index is greater that of the prev index then sum it up
  //   else
  //   start from this index and add all the elements that are greater than this.
}
int main()
{   vector<int>ar{10, 70, 20, 30, 50, 11, 30};
    maxSumIncreasingSubsequence(ar);
    return 0;
}