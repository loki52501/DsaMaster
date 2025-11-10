#include<bits/stdc++.h>
using namespace std;
void reverar(int l,int r, int ar[])
{
    if(l>=r)return;
    swap(ar[l],ar[r]);
    reverar(l+1,r-1,ar);
    return;
}
void swap(int& i, int& j)
{
int temp=i;
i=j;
j=temp;
}
int main()
{
int ar[5]={1,2,3,4,5};
reverar(0,4,ar);
for(int i=0;i<5;i++)
cout<<ar[i]<<" ";

}