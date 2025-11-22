#include <vector>
using namespace std;


bool isSafe(int num,vector<vector<int>>&board,int row,int column)
{cout<<row<<column<<" current checking\n";
  for(int i=0;i<9;i++)
    {
      if(board[row][i]==num)
        return false;
       if(board[i][column]==num)
        return false;
         if(board[3*(row/3)+(i/3)][3*(column/3)+(i%3)]==num)
          return false;
      }
  return true;
}
bool solve(vector<vector<int>>&board)
{for(int row=0;row<board.size();row++)
  {for(int column=0;column<board.size();column++)
    { if(board[row][column]==0){
    {for(int i=1;i<=9;i++)
      if(isSafe(i,board,row,column))
      { board[row][column]=i;
           if(solve(board)==true)
             return true;
          else
             board[row][column]=0;
      }
    }}}}
 return true;
}
vector<vector<int>> solveSudoku(vector<vector<int>> board) {
  solve(board);
  return board;
}