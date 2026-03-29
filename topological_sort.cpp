#include <vector>
using namespace std;

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
   unordered_map<int,vector<int>> nextjob;
   unordered_map<int,int>jobcount;
   for(auto dep:deps)
   {
        if(jobcount[dep[1]].count())
        jobcount[dep[1]]++;
        else
        jobcount[dep[1]]=1;
        
        nextjob[dep[0]].push_back(dep[1]);
    }
    for(auto orderedjob:nextjob)
    {

    }

  return {};
}
