#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  bool ismove=false;
  int firstseen=-1;
  for(int i=0;i<array.size();i++)
    {
      if(array[i]==toMove&&!ismove)
      {
        ismove=true;
        firstseen=i;
      }
      else if(array[i]!=toMove && ismove)
      {
        int temp=array[i];
        array[i]=array[firstseen];
        array[firstseen]=temp;
        if(abs(firstseen-i)>1){
          firstseen+=1;
        }
        else
          firstseen=i;
      }
    }
  return array;
}
