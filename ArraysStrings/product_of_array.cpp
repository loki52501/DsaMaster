#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) {
  int n=array.size();

  vector<int>ans(n,1);
  int productall=1;
  for(int i=0;i<n;i++)
    {
      ans[i]=productall;
      productall=productall*array[i];
    }
  productall=1;
  for(int i=n-1;i>=0;i--)
    {
      ans[i]=ans[i]*productall;
      productall=productall*array[i];
    }

  return ans;
}
