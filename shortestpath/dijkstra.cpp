#include <vector>
using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
  int n=edges.size();
   vector<int> dist(n,-1);
  vector<bool>visited(n,false);
  vector<int>d(n,INT_MAX);
  d[start]=0;
  for(int i=0;i<n;i++)
    {
    int u=-1;
      int minVal=INT_MAX;
      for(int j=0;j<n;j++)
        if(!visited[j] && d[j]<minVal){
          minVal=d[j];
          u=j;
        }
      if(u==-1)
        break;
      visited[u]=true;
      for(auto edge:edges[u])
        {
          int v=edge[0];
          int weight=edge[1];
          if(d[u]!=INT_MAX && d[u]+weight <d[v]){
            d[v]=d[u]+weight;
          }
        }
    }
  
   for(int i=0; i<n; ++i) {
        if(d[i] == INT_MAX) {
            dist[i] = -1;
        } else {
            dist[i] = d[i];
        }
    }

    return dist;
}


