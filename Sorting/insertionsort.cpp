#include <vector>
#include<iostream>
using namespace std;

vector<int> insertionSort(vector<int> &array) {

  for(int i=1;i<array.size();i++)
    {
      for(int j=i;j>0;j--)
        if(array[j-1]>array[j])
        {
          int temp=array[j];
          array[j]=array[j-1];
          array[j-1]=temp;
        }
        
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