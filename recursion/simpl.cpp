#include<iostream>
#include<cstring>
using namespace std;

void lr(int n)
{
  if(n<=0)
  return ;
  lr(n-1);
  cout<<n;
  return  ;
}
int main()
{
int n;
int denoms[n+1];
memset(denoms,-1,sizeof(denoms));
lr(8);
}