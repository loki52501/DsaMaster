#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void recvv( vector<int>&array, int front, int rear)
{
 if(front > rear)
 return ;
 swap(array[front],array[rear]);
 recvv(array,front+1,rear-1);
 return;
}
int main()
{
    vector<int>inp{3, 5, -4, 8, 11, 1, -1, 6};
int target=10;
recvv(inp,0,inp.size()-1);
for(auto so:inp)
cout<<so<<" ,";
}