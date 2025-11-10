// print subseqence whose sum is K
#include<bits/stdc++.h>
using namespace std;
void printarray(vector<int>);
// void seqsum(int targetsum,int sum,int n,vector<int> ar,vector<int> ors)
// {
// if(n>=ors.size())
// {
//     if(sum==targetsum)
//     {cout<<"the target sum reached for subsequence that is:\n";
//         printarray(ar);
          
//     }

//     return;
// }
// ar.push_back(ors[n]);
// sum+=ar.back();
// seqsum(targetsum,sum,n+1,ar,ors);
// sum-=ar.back();
// ar.pop_back();
// seqsum(targetsum,sum,n+1,ar,ors);
// return;
// }

int seqsum(int targetsum,int sum, vector<int> ors, int n)
{int l=0,r=0;
    if(n>=ors.size())
    {
        if(sum==targetsum)
        {
            return 1;
        }
        return 0;
    }
    sum+=ors[n];
    l=seqsum(targetsum,sum,ors,n+1);
    sum-=ors[n];
    r=seqsum(targetsum,sum,ors,n+1);
return l+r;
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
cout<<seqsum(n,0,ors,0)<<" total no of subsequent sums;\n";    
    return 1;
}