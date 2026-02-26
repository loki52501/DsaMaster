using namespace std;

int majorityElement(vector<int> array) {
  int num=0,count=0;
  for(int i=0;i<array.size();i++)
    {
      if(num==array[i])
      {
        count++;
      }
      else
      {
       
        if(count>0)
          count--; 
        else{
count=0;
        num=array[i];}
      }
    }
  return num;
}
