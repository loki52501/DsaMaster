using namespace std;

int optimalFreelancing(vector<unordered_map<string, int>> jobs) {
 int totalmax=0;
  vector<pair<int,int>> reorder;
  unordered_map<int,bool> isthere;
  if(jobs.size()==0)
    return 0;
  for(int i=0;i<jobs.size();i++)
    {
      reorder.push_back(make_pair(jobs[i]["deadline"],jobs[i]["payment"]));
    }
  sort(reorder.begin(),reorder.end(),[](pair<int,int> a, pair<int,int> b){return a.second>b.second;});

  for(auto j : reorder){
    if(isthere.size()==7)break;
  for(int i=j.first;i>0;i--)
    { if(!isthere[i])
    {totalmax+=j.second;
     isthere[i]=true;
     break;
    }
    
    }        
    cout<<j.first<<" "<<j.second<<"\n"; 
    
    }
  return totalmax;
}
