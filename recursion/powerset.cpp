#include<iostream>
#include <vector>
using namespace std;
void subsety(const vector<int>&array,vector<int>&result,vector<vector<int>>&res, int i)
{
  if(i>=array.size())
 {res.push_back(result); 
  return;}
  result.push_back(array[i]);
  subsety(array,result,res,i+1);
  result.pop_back();
  subsety(array,result,res,i+1);
  
}

int main(){
    vector<int>arra{1,2,3,4,5};
    vector<int>res;
    vector<vector<int>>result;
    subsety(arra,res,result,0);
    for(auto i:result)
    {
      for(auto j: i)
      cout<<j<<",";
      cout<<"\n";
    }
}