#include<bits/stdc++.h>
#include<vector>
using namespace std;
void merge(int ar[],int mid,int start,int end){
    int n1=mid-start+1;
    int n2=end-mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)
    L[i]=ar[start+i];
    for(int j=0;j<n2;j++)
    R[j]=ar[j+mid+1];

    int i=0,j=0,k=start;
    while(i<n1&& j<n2)
    {
       if(L[i]<R[j])
       {
        ar[k]=L[i];
        i++;
       }
       else{
        ar[k]=R[j];
        j++;
       }
       k++;
    }
    while(i<n1)
    {
        ar[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        ar[k]=R[j];
        j++;
        k++;
    }

}

void mergesort(int ar[],int start,int end)
{int mid=(start+end)/2;
    if(start>=end)
    return;
    mergesort(ar,start,mid);
    mergesort(ar,mid+1,end);
    merge(ar,mid,start,end);
}
int main()
{
    int ar[]={5,4,3,2};
    mergesort(ar,0,3);
    for(int i=0;i<4;i++)
    cout<<ar[i]<<" ";
}