#include<iostream>
using namespace std;

int levenshteinDistance(string str1, string str2) {
  string maxst,minst;
  
  if(str1.length()>str2.length())
  {maxst=str1;
    minst=str2;}
  else
  {maxst=str2;
      minst=str1;}

    int ar[maxst.length()+1][minst.length()+1];

  
  for(int i=0;i<maxst.length()+1;i++)
    ar[i][0]=i;
  for(int i=0;i<minst.length()+1;i++)
    ar[0][i]=i;
  
  
  for(int i=1;i<maxst.length()+1;i++)
    {
      for(int j=1;j<minst.length()+1;j++)
        { 
          if(maxst[i-1]==minst[j-1])
      {
        ar[i][j]=ar[i-1][j-1];
      }else
      {
        ar[i][j]=1+min(min(ar[i-1][j-1],ar[i][j-1]),ar[i-1][j]);
      }
        
    }} 
  for(int i=0;i<=maxst.length(); i++)
    cout<<ar[i][0]<<"\n";
  return ar[maxst.length()][minst.length()];
}