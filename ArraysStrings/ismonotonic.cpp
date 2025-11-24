using namespace std;

bool isMonotonic(vector<int> array) {
  if(array.empty()||array.size()==1)
    return true;
  int isincdec=-1;
bool indextostartlooking=false;
  for(int i=1;i<array.size();i++)
    {
      if(!indextostartlooking && array[i]==array[i-1])
      {
      continue;
      }
      if(!indextostartlooking && array[i]>array[i-1])
      {isincdec=1;
      indextostartlooking=true;
      }
      else if(!indextostartlooking && array[i]<array[i-1])
      {
        isincdec=0;
        indextostartlooking=true;
      }
      else if(array[i]>array[i-1] && isincdec!=1)
        return false;
      else if(array[i]<array[i-1]&& isincdec!=0)
        return false;
    }
  return true;
}
