#include<unordered_map>
#include<iostream>
using namespace std;

int firstNonRepeatingCharacter(string string) {
   unordered_map<char,int>scount;
  int count=0;
  for(auto i:string)
    {
      scount[i]+=1;
    }
  for(auto c:string)
    {
      if(scount[c]==1)
         return string.find(c);
    }
  return -1;
}
