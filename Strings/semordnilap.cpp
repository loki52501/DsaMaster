#include<string>
using namespace std;

vector<vector<string>> semordnilap(vector<string> words) {

  vector<vector<string>> res;
  for(int i=0;i<words.size();i++)
    {  vector<string> res1;
      bool happen=false;
      res1.push_back(words[i]);
     string reversestring=words[i];
      reverse(reversestring.begin(),reversestring.end());
      for(int j=i+1;j<words.size();j++)
        if(reversestring==words[j])
        {
          res1.push_back(words[j]);
        happen=true;
        }
    if(happen) 
     res.push_back(res1);
    }
    
  return res;
}
