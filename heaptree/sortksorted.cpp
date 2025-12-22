
#include <vector>
using namespace std;

vector<int> sortKSortedArray(vector<int> array, int k) {
  int n=array.size(),sortedIndex=0,i=0;
  priority_queue<int,vector<int>,greater<int>>sortedarray;
  if(n==0)
    return{ };
  if(n==1)
    return array;
   while(k>=n)
          k--;
  while(sortedIndex<n)
    {
     
      while(i<=k && k<n){sortedarray.push(array[i]);i++;}
      k+=1;
      array[sortedIndex++]=sortedarray.top();
      sortedarray.pop();
    }
  return array;
}
