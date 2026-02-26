#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target) {
        int ll=0,hl=nums.size();
        int mid=0;
        while(ll<=hl)
        {
            mid=(ll+hl)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]<target)
            ll=mid+1;
            else if(nums[mid]>target)
            hl=mid-1;
        }
        return -1;
    }

int main()
{
    vector<int> arr{-1,0,3,5,9,12};
    cout<<search(arr,9);
}