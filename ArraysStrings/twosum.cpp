#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> twosum(const vector<int>& array, int target)
{
 unordered_map<int,int>sol;
 vector<int>soli;

 for(int i=0;i<array.size();i++)
 {  if(sol.count(array[i]))
    {
      soli.push_back(array[i]);
      soli.push_back(target-array[i]);
 
      break;
    }
    sol[target-array[i]]=array[i];

}
return soli.empty() ? vector<int>{-1, -1} : soli;
}
int main(){
vector<int>inp{3, 5, -4, 8, 11, 1, -1, 6};
int target=10;
vector<int>sol=twosum(inp,target);
for(auto so:sol)
cout<<so<<" ,";

}