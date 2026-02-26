#include<iostream>
#include<vector>
using namespace std;
vector<int> missingNumbers(vector<int> nums) {
  
  int siz=nums.size();
  int sizereally=siz+2;
  int totsum=(sizereally*(1+sizereally))/2;
  int actsum=[nums,siz](){
    int res=0;
    for(int i=0;i<siz;i++)
      res+=nums[i];
    return res;
  }();
  cout<<actsum;
  return {};
}
int main()
{
    vector<int> number{1,4,3};
    missingNumbers(number);
}
