// print subseqence whose sum is K
#include<bits/stdc++.h>
using namespace std;
void printarray(vector<int>);
void seqsum(int targetsum, vector<int> ors)
{int sum=0;
vector<int> ar;
int n=0;

for(int i=0;i<ors.size();i++)
if(n>=ors.size())
{
    if(sum==targetsum)
    {cout<<"the target sum reached for subsequence that is:\n";
        printarray(ar);
          
    }

    return;
}
ar.push_back(ors[n]);
sum+=ar.back();
seqsum(targetsum,sum,n+1,ar,ors);
sum-=ar.back();
ar.pop_back();
seqsum(targetsum,sum,n+1,ar,ors);
return;
}

void printarray(vector<int> ar)
{cout<<"[";
    for(int i=0;i<ar.size();i++)
    cout<<ar[i]<<" ";
    cout<<"]\n";
}

int main()
{
    vector<int>ors{3,4,5,6};
    int n;
    cout<<" enter the target sum number: ";
    cin>>n;
    
    vector<int>ar;
    seqsum(n,ors);
    
    return 1;
}