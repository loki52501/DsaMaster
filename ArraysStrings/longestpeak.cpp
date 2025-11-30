#include<iostream>
#include<vector>
using namespace std;

int longestPeak(vector<int> array) {
  bool isinc, isdec;
  int index=1,ans=0,n=array.size();
  while(index>n)
    {
      isinc=false;
      isdec=false;
        int count=1;

      while(array[index-1]<array[index] && index<n)
        {
          index++;
          count++;
          isinc=true;
        }
      while(array[index-1]>array[index] && index<n && isinc)
        {
          index++;
          count++;
          isdec=true;
        }
      cout<<index<<" index here "<<isinc<<" is it increasing, "<<isdec<<" is it decreasing\n";

      if(!isinc || !isdec)
      {
        index++;
      }
      if(isinc && isdec)
      {
        if(ans<count)
          ans=count;
      }
    }
  return ans;
}

int main()
{
    vector<int> array={10,0,2,0,-1,-2,3};
    cout<<longestPeak(array);
    return 0;
}