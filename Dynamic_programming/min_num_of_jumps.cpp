// #include <vector>
// using namespace std;
// int minhelper(int ,int ,vector<int>,int ,int );
// int minNumberOfJumps(vector<int> array) {
//   // Write your code here.
//   int count=1;
//   int res= minhelper(0,array[0],array,count,array.size());
//   if(res==INT_MAX)
//     return 0;
//   else if(res==0)
//     return res;
//   else
//     return res;
// }
// int minhelper(int currindex,int value,vector<int>array,int count,int n)
// {
//   if(n==1) return 0;
//   if(currindex+value==n-1) return count;
//   if(value==0)return INT_MAX; 
//   if(currindex+value>n-1 )
//     return minhelper(currindex,value-1,array,count,n);
//   else
//   return min(minhelper(currindex,value-1,array,count,n),minhelper(currindex+value,array[currindex+value],array,count+1,n));
  
// }
#include <vector>
using namespace std;

int minNumberOfJumps(vector<int> array) {
    int n = static_cast<int>(array.size());
    if (n <= 1) return 0;
    int jumps = 0;
    int currentEnd = 0;   // farthest index we can reach with current number of jumps
    int farthest = 0;     // farthest index reachable while exploring the current layer

    for (int i = 0; i < n - 1; ++i) { // stop at n-2 to avoid an extra jump at the end
        farthest = max(farthest, i + array[i]);
        if (i == currentEnd) {        // finish current layer; commit a jump
            ++jumps;
            currentEnd = farthest;
            if (currentEnd >= n - 1) break; // already can reach or pass the end
        }
    }
    return jumps;
}
