#include <vector>

using namespace std;

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {

  if(arrayOne[0] !=arrayTwo[0])
  {
    return false;
  }
  if(arrayOne.size()==0 && arrayTwo.size()==0)
return true;
if(arrayOne.size()!=arrayTwo.size())
  return false;

int root=arrayOne[0];
vector<int>Leftone;
vector<int>Lefttwo;

for(int i=1;i<arrayOne.size();i++)
{
    if(arrayOne[i]<root)
    arrayOne
    if(arrayTwo[i]<root)
    Lefttwo.append(arrayTwo[i]);
}
bool left=sameBsts(arrayOne, arrayTwo);
vector<int>Rightone;
vector<int>Righttwo;
for(int i=1;i<arrayOne.size();i++)
{
    if(arrayOne[i]>=root)
    Rightone.append(arrayOne[i]);
    if(arrayTwo[i]>=root)
    Righttwo.append(arrayTwo[i]);
}
return sameBsts(Leftone,Lefttwo) && sameBsts(Rightone,Righttwo);
}