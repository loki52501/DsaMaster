#include<unordered_map>
#include<iostream>
using namespace std;

vector<string> commonCharacters(vector<string> strings) {
  unordered_map<char,int> s;
  vector<string> letters;
  for(int strs=0;strs<strings.size();strs++)
    {
     string copycat="";
     string orgcat=strings[strs];
      for(int letter=0;letter<orgcat.length();letter++)
        {
          if(s.find(orgcat[letter])!=s.end() && copycat.find(orgcat[letter])==string::npos)
          {s[orgcat[letter]]+=1;
    
          }else if(s.find(orgcat[letter])==s.end())
          { s[orgcat[letter]]=1;

          }
          
          copycat.push_back(orgcat[letter]);
        }
    }
  for(auto character:s)
    {cout<<character.first<<", "<<character.second<<"\n";
      if(character.second==strings.size())
      {  
          letters.push_back(string(1,character.first));
        cout<<letters[0]<<"\n";
      }
    }
  
  
  return letters;
}
