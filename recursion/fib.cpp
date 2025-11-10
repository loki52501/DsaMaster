#include<bits/stdc++.h>
using namespace std;
int fibo(int n)
{
 if(n<=2)
return 1;
return fibo(n-1)+fibo(n-2);
}
int main()
{
int n;
cout<<" enter the numberth term you want to find fibonacci:";
cin>>n;
cout<<"\n the answer is :"<<fibo(n);
return 0;
}