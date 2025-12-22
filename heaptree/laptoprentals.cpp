#include <vector>
using namespace std;

auto customcompare=[](vector<int>&ele1,vector<int>&ele2)
{
  return ele1[1]>ele2[1];;
};
int laptopRentals(vector<vector<int>> times) {
  priority_queue<vector<int>,vector<vector<int>>,decltype(customcompare)>res(customcompare);
  sort(times.begin(),times.end(),less<vector<int>>());
  int n=times.size();
  for(auto i:times)
    {
      cout<<i[0]<<" "<<i[1]<<" \n w";
    }
  for(int i=0;i<n;i++)
    {
      if(i==0)
        res.push(times[i]);
      else if(res.top()[1]<=times[i][0])
      {
        res.pop();
        res.push(times[i]);
      }
      else if(res.top()[1]>times[i][0])
      {
        res.push(times[i]);
      }
    }

  return res.size();
}
