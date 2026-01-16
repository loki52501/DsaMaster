#include<algorithm>
using namespace std;

vector<int> sunsetViews(vector<int> buildings, string direction) {
  bool rev=direction=="EAST";
  vector<int> answer;
  int iterstart=rev?buildings.size()-1:0;
  int iterend=rev?-1:buildings.size();
  int step=rev?-1:1;
  if(!buildings.empty())
  {   answer.push_back(iterstart);

  for(;iterstart!=iterend;iterstart+=step)
    {
      if(buildings[answer.back()]<buildings[iterstart] && !rev)
        answer.push_back(iterstart);
      else if(buildings[answer.front()]<buildings[iterstart] && rev)
        answer.insert(answer.begin(),iterstart);
    }}

  return answer;
}
