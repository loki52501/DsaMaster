#include <vector>
using namespace std;

int dfs(vector<vector<int>>&matrix,int i,int j, int row, int column,vector<vector<int>>&visited);

vector<int> riverSizes(vector<vector<int>> matrix) {
  int row=matrix.size(), column=matrix[0].size();
  vector<int>sizes;
  vector<vector<int>>visited(row,vector<int>(column,0));
  for(int i=0;i<row;i++)
    for(int j=0;j<column;j++)
      {
        if(visited[i][j]==0 && matrix[i][j]==1)
        { int size=dfs(matrix,i,j,row,column,visited);
        sizes.push_back(size);
        }
      }
  return sizes;
}
int dfs(vector<vector<int>>&matrix,int i,int j, int row, int column,vector<vector<int>>&visited)
{
  if(i<0 || i>=row ||j<0||j>=column)
    return 0;
  if(matrix[i][j]==0 || visited[i][j]==1)
    return 0;
  visited[i][j]=1;
  int size=1;
  size+=dfs(matrix,i+1,j,row,column,visited);//up
  size+=dfs(matrix,i-1,j,row,column,visited);//down
  size+=dfs(matrix,i,j+1,row,column,visited);//right
  size+=dfs(matrix,i,j-1,row,column,visited);//left
  return size;
}