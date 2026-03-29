#include <vector>
using namespace std;

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
   unordered_map<int,vector<int>> nextjob;
   unordered_map<int,int>jobcount;
   for(auto dep:dep)
   {
        if(jobcount[dep[0]].count())
        jobcount[dep[0]]++;
        else
        jobcount[dep[0]]=1;
        
        nextjob[dep[0]].push_back(dep[1]);
    }
    for(auto orderedjob:nextjob)
    {
        
    }

  return {};
}
