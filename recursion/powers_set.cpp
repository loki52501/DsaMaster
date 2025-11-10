#include<bits/stdc++.h>
#include<vector>
using namespace std;
void printarray(vector<int>);
void powerset(int n,vector<int>ar,vector<int>ora)
{
  if(n>=ora.size())
  {
  printarray(ar);
  return;
  }
  ar.push_back(ora[n]);
  powerset(n+1,ar,ora);
  ar.pop_back();
  powerset(n+1,ar,ora);
  return;

}
void printarray(vector<int> ar)
{cout<<"[";
    for(int i=0;i<ar.size();i++)
    cout<<ar[i]<<" ";
    cout<<"]\n";
}
int main()
{
    vector<int>oraa{3,2,1,4};
    vector<int>ar;
    powerset(0,ar,oraa);
}