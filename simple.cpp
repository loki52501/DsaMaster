#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int x=0;
    vector<int>a{1,0,0,1};
    while(x<a.size())
    {
        while(a[x++]==0)
             cout<<x<<" ";
        cout<<" x is "<<x<<"\n";
    }
    return 0;

}