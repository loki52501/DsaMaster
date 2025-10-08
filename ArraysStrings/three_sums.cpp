#include <vector>
#include<iostream>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  vector<vector<int>> res;
  sort(array.begin(),array.end());
  int siz=array.size();
  for(int i=0;i<siz;i++)
    {   vector<int>p1;
     
      int left=i+1;
    int right=siz-1;
  while(right>left)
    {
      if((array[i]+array[left]+array[right])==targetSum)
      { cout<<"im here";
        p1.push_back(array[i]);
       p1.push_back(array[left]);
       p1.push_back(array[right]);
       res.push_back(p1);
       p1={};
       right--;
       left++;
      }
      else if((array[i]+array[left]+array[right])>targetSum)
      {
        right--;}
      else if((array[i]+array[left]+array[right])<targetSum)
      {cout<<"im here";
       left++;}
    }
    }
  return res;
}
