#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int powers(int n,int e)
{
if(e==0)
return 1;

if(e%2==0)
{int half;
    half=powers(n,e/2);
    return half*half;
}
else
return n*powers(n,e-1);

}
int main()
{
    int num=10, power=5;
   cout<<powers(2,6);
}