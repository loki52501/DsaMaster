#include<iostream>
using namespace std;

int factor(int);
int numberOfWaysToTraverseGraph(int width, int height) {
  int r=width-1;
  int d=height-1;
  int res=factor(r+d)/(factor(r)*factor(d));
  return res;
}

int factor(int num)
{
  if (num<=1)
    return 1;
  else
    return num*factor(num-1);
}