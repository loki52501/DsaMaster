#include <vector>
using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
  int countered=0,counteblue=0;
  sort(redShirtHeights.begin(),redShirtHeights.end(),greater<int>());
  sort(blueShirtHeights.begin(),blueShirtHeights.end(),greater<int>());
  bool red=false, blue=false;
        if(redShirtHeights[0]>blueShirtHeights[0])
        red=true;
      if(redShirtHeights[0]<blueShirtHeights[0])
        blue =true;
  for(int i=0;i<redShirtHeights.size();i++)
    {cout<<red<<" , "<<blue<<" , "<<"\n";
           if(red && redShirtHeights[i]>blueShirtHeights[i] )
                 countered++;
           else if (blue && redShirtHeights[i]<blueShirtHeights[i] )
             counteblue++;
      
    }
  if(countered == redShirtHeights.size() || counteblue == redShirtHeights.size() )
    return true;

  return false;
}