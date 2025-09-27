#include <iostream>
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> &array) {

  for(int i=0;i<array.size();i++)
    {
     for(int j=i+1;j<array.size();j++)
      if(array[i]>array[j])
      {
        int temp=array[i];
        array[i]=array[j];
        array[j]=temp;
      }
    }
  return array;
}

int main()
{
    vector<int> array={-4, 5, 10, 8, -10, -6, -4, -2, -5, 3, 5, -4, -5, -1, 1, 6, -7, -6, -7, 8};
    bubbleSort(array);
    for(auto i: array)
    cout<<i<<", ";
return 0;
}
