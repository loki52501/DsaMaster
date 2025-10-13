#include<stack>
using namespace std;


vector<vector<int>> stableInternships(
  vector<vector<int>> interns, vector<vector<int>> teams
) {
  vector<vector<int>>res;
  stack<int> free_interns;
  vector<map<int,int>>teammaps;
  vector<int> interns_index(interns.size(),0);
  map<int,int> matches;
  /* for teams*/
  for(int i=0;i<teams.size();i++)
    {map<int,int>teammap;
        for(int j=0;j<teams[i].size();j++)
          {int intern=teams[i][j];
            teammap[intern]=j;
          }
          teammaps.push_back(teammap);
    }
  for(int i=0;i<interns.size();i++)
    free_interns.push(i);
  while(!free_interns.empty())
    {
      int currintern=free_interns.top();
      free_interns.pop();
      int intern_index=interns_index[currintern];
      int team_currpreference=interns[currintern][intern_index];
      if(matches.find(team_currpreference)==matches.end())
      {
        matches[team_currpreference]=currintern;
        cout<<"matches"<<endl;
      }
      else{
        int previntern=matches[team_currpreference];
        int currrank=teammaps[team_currpreference][currintern];
        int prevrank=teammaps[team_currpreference][previntern];
        if(currrank<prevrank)
        {
          matches[team_currpreference]=currintern;
          free_interns.push(previntern);
        }
        else
          free_interns.push(currintern);
}
      interns_index[currintern]++;
      
    }

  for(auto it:matches)
    res.push_back({it.second,it.first});
  return res;
}
