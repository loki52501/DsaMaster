#include<unordered_set>
using namespace std;

bool zeroSumSubarray(vector<int> nums) {
  unordered_set<int>sf;
  int sum=0;
  for(int i=0;i<nums.size();i++)
    {
      if(nums[i]==0)
        return true;
      sum+=nums[i];
      
      if(sum==0 || sf.find(sum) !=sf.end())
        return true;
      sf.insert(sum);
    }
  return false;
}
