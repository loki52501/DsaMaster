#include<unordered_map>
#include<string>
#include<iostream.h>
using namespace std;

bool generateDocument(string characters, string document) {

  
  unordered_map<char,int> ccount;
  for(auto i:characters)
    {
        ccount[i]++;
      
    }
  unordered_map<char,int> scount;
  for(auto i:document)
    {
     ccount[i]--;
      if(ccount[i]<0)return false;
    }
  
  
  return true;
}
