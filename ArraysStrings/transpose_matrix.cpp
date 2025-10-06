using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>> matrix) {
  int row=matrix.size();
  int column;
  if(!matrix.empty())
    column=matrix[0].size();
  else
    return {};
  
  vector<vector<int>>res(column,vector<int>(row));
  cout<< matrix.size()<<"\n";
  for(int i=0;i<matrix.size();i++)
    {
      for(int j=0;j<matrix[i].size();j++)
        res[j][i]=matrix[i][j];
    }
  return res;
}
