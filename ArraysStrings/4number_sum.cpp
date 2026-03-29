#include <vector>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
  unordered_map<int,vector<pair<int,int>>>summap;
  vector<vector<int>>ans;
  for(int i=0;i<array.size();i++)
    {
    for(int j=i+1;j<array.size();j++)
    {vector<int>res;
        int sumone=targetSum-(array[i]+array[j]);
        if(summap.count(sumone))
        {
             
             auto others=summap[sumone];
             for(auto other:others)
             {
               res.push_back(array[i]);
             res.push_back(array[j]);
                res.push_back(other.first);
                res.push_back(other.second);
                ans.push_back(res);
               res={};
             }
             
        } 
    }
    for(int k=0;k<=i-1;k++)
    {
        int sumtwo=(array[i]+array[k]);
        summap[sumtwo].push_back({array[i],array[k]});
    }
    
    }
  return ans;
}
