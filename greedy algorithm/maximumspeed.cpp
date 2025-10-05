#include <vector>
using namespace std;

int tandemBicycle(
  vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds, bool fastest
) {
  int maxs=0;
  if(fastest)
  {
    sort(redShirtSpeeds.begin(), redShirtSpeeds.end(), greater<int>());
        sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());

  }
  else{
       sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
        sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
  }
for(int i=0;i<redShirtSpeeds.size();i++)
  {cout<<redShirtSpeeds[i]<<" , "<<blueShirtSpeeds[i]<<","<<maxs<<"\n";
    if(redShirtSpeeds[i]>=blueShirtSpeeds[i])
       maxs+=redShirtSpeeds[i];
    else if(blueShirtSpeeds[i]>=redShirtSpeeds[i])
      maxs+=blueShirtSpeeds[i];
  }
  
  return maxs;
}