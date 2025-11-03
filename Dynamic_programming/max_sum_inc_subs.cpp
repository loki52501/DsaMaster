#include <vector>
#include<iostrea>
using namespace std;

vector<int> buildsequence(vector<int>array, vector<int>sequences,int maxsumidx)
{
  int i=maxsumidx;
  vector<int> res;
  while(maxsumidx!=-1)
    {
     res.insert(res.begin(),array[maxsumidx]);
      maxsumidx=sequences[maxsumidx];
    }
  return res;
}
vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
  vector<int>sums(array), se(array.size(),-1);
  int maxsumidx=0;
  for(int i=0;i<array.size();i++)
    {
      int curr=array[i];
      for(int j=0;j<i;j++)
        {
          if(curr>array[j] && sums[j]+curr>= sums[i])
          {sums[i]=sums[j]+curr;
           se[i]=j;
          }
        }
      if(sums[i]>=sums[maxsumidx])
        maxsumidx=i;
      
    }
  return {
    {sums[maxsumidx]},  // Sum of sequence.
    buildsequence(array,se,maxsumidx)   // Elements of the sequence.
  };
}
