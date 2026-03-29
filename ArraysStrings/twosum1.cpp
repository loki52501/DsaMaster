class Solution {
public:
    vector<int> twoSum(vector<int>& array, int targetSum) {
 unordered_map<int,int>whatis;
  vector<int>ans;
  for(int i=0;i<array.size();i++)
    {
      int sum=targetSum-array[i];
      whatis[sum]=i;
    }
  for(int i=0;i<array.size();i++)
    {
      if(whatis.count(array[i]) && whatis[array[i]]!=i)
      {
        ans.push_back(i);
        ans.push_back(whatis[array[i]]);
        
        break;
      }
    }
  return ans;
    }
};