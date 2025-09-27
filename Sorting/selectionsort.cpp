#include <vector>
#include<iostream>
using namespace std;

vector<int> selectionSort(vector<int> array) {

  for(int i=0;i<array.size();i++)
    {
      int min=i;
      for(int j=i+1;j<array.size();j++)
        {
          if(array[j]<array[min])
          {min=j;}
        }
      int temp=array[min];
      array[min]=array[i];
      array[i]=temp;
    }
  return array;
}
int main()
{
    vector<int> array={-4, 5, 10, 8, -10, -6, -4, -2, -5, 3, 5, -4, -5, -1, 1, 6, -7, -6, -7, 8};
    insertionSort(array);
    for(auto i: array)
    cout<<i<<", ";
return 0;
}