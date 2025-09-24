###
// basic binary search program.
#include <vector>
#include<iostream>
using namespace std;

int binarySearch(vector<int> array, int target) {

  int firstindex=0;
  int lastindex=array.size()-1;
  int mid=(firstindex+lastindex)/2;
  while(lastindex>firstindex)
    {
      if(array[mid]==target)
         break;
      else if(array[mid]>=target)
        lastindex=mid-1;
     else if(array[mid]<=target)
       firstindex=mid+1;
      mid=(firstindex+lastindex)/2;
        
    }
if(array[mid]!=target) return -1;
  return mid;
}
