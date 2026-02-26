#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int sumdigits(int number )
{
  if(number==0)
  return 0 ;

return number%10+sumdigits(number/10);
}
int main()
{
    int digit=298;
    int sums=0;
    sums=sumdigits(digit);
    cout<<sums;
}
