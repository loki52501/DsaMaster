#include <vector>
#include<iostream>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
  int currsum=array[0];
  int maxsum=currsum;
  for(int i=1;i<array.size();i++)
    {
    if((currsum+array[i])<array[i])
      currsum=array[i];
    else
      currsum+=array[i];
      if(currsum>maxsum)
        maxsum=currsum;
    cout<<maxsum<<" "<<i<<" "<<array[i]<<"\n";
    }
      
  return maxsum;
}
