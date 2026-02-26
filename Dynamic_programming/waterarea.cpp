#include <vector>
using namespace std;

int waterArea(vector<int> heights) {
  int left=0, right=heights.size()-1;
  int maxLeft=0,maxRight=0;
  int trappedWater=0;
  while(left<right)
    {
      if(heights[left]<heights[right])
      {
        maxLeft=max(maxLeft,heights[left]);
        trappedWater+=maxLeft-heights[left++];
      }
      else
      {
        maxRight=max(maxRight,heights[right]);
          trappedWater+=maxRight-heights[right--];

      }
    }
  return trappedWater;
}
