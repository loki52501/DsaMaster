#include <vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
   unordered_map<int,vector<int>> nextjob;
   unordered_map<int,int>jobcount;
   vector<int>res;
   queue<int> order;
   for(auto dep:deps)
   {
        if(jobcount.count(dep[1]))
        jobcount[dep[1]]++;
        else
        jobcount[dep[1]]=1;
        
        nextjob[dep[0]].push_back(dep[1]);
    }
    for(auto job:jobs)
    { 
        if(jobcount[job]==0)
        order.push(job);
        
    }
    while(!order.empty())
    {
        int curr=order.front();
      res.push_back(curr);
      order.pop();
      for(auto nextb:nextjob[curr])
      {  jobcount[nextb]--;
  if(jobcount[nextb] == 0)
        queue.push(nextb);
          
    }
    }

  return {};
}
