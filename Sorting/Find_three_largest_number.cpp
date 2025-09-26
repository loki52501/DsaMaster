#include <vector>
#include<iostream>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
  vector<int> three={INT_MIN, INT_MIN, INT_MIN};
  for(int i=0;i<array.size();i++)
    {
      if(three[2]<array[i])
      {
      three[0]=three[1];
        three[1]=three[2];
        three[2]=array[i];
      }
      else if (three[1]<array[i])
      {three[0]=three[1];
      three[1]=array[i];
      }
      else if (three[0]<array[i])
        three[0]=array[i];
    }
  return three;
}
