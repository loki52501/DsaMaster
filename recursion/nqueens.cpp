
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>>ans;
      vector<string>boards;
      string board(n,'.');
      for(int i=0;i<n;i++)
      boards.push_back(board);
      vector<int>rows(n,0);
      vector<int>ud(2*n-1,0);
      vector<int>ld(2*n-1,0);
      solve(0,boards,ans,rows,ud,ld,n);
      return ans;

        
    }
    void solve(int column, vector<string>board,vector<vector<string>>& ans,vector<int> rows,vector<int>ud,vector<int>ld,int n)
    {
        if(column==n)
        {ans.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++)
        {
            if(rows[row]==0 && ud[row+column]==0 &&ld[n-1+column-row]==0)
            {
                rows[row]=1;
                ud[row+column]=1;
                ld[n-1+column-row]=1;
                board[row][column]='Q';
                solve(column+1,board,ans,rows,ud,ld,n);
                rows[row]=0;
                ud[row+column]=0;
                ld[n-1+column-row]=0;
                board[row][column]='.';
            }}
    }
    
};