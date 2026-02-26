#include<iostream>
using namespace std;
#include <vector>
using namespace std;


void permuteBacktrack(vector<int>& arr, int start, vector<vector<int>>& result) {
    
    if(start==arr.size()-1)
{result.push_back(arr);
return;
}    
    for(int i=start;i<arr.size();i++)
    {swap(arr[start],arr[i]);
    permuteBacktrack(arr,start+1,result);
    swap(arr[start],arr[i]);}
}
int main()
{
    vector<int>array{1,2,3};
    vector<vector<int>>res;
    permuteBacktrack(array,0,res);
    for(auto in:res)
    {for(auto ele:in)
    cout<<ele<<", ";
    cout<<"\n";}
}