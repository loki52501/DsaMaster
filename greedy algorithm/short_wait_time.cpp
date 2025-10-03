using namespace std;

int minimumWaitingTime(vector<int> queries) {
  sort(queries.begin(),queries.end());
  int sums=0,res=0;
  for (int i=0;i<queries.size()-1;i++)
    {
        sums+=i;
        res+=i;
    }
  return sums;
}
