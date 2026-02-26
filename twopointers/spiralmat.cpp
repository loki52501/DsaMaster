#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int lrows=0,lcols=0,mrows=matrix.size()-1,mcols=matrix[0].size()-1,sized=0,i=0,j=0;
    vector<int>res;
    while(mrows>=lrows && mcols>=lcols)
    {
            while(j<=mcols)
            res.push_back(matrix[i][j++]);
            j--;
            i++;
            while(i<=mrows)
            res.push_back(matrix[i++][j]);
            i--;
            j--;
            if(mrows>lrows)
            while(j>lcols)
            res.push_back(matrix[i][j--]);
            if(mcols>lcols)
            while(i>lrows)
            res.push_back(matrix[i--][j]);
            mrows--;
            mcols--;
            lrows++;
            lcols++;
            i=lrows;
            j=lcols;
            
    }
    return res;
}
void print(vector<int> ma){
    for(auto m:ma)
    std::cout<<m<<"\n";
}
    int main()
    {
          /*vector<vector<int>> mat = {  {1, 2, 3},                                                                                           
      {4, 5, 6},
      {7, 8, 9}
  };*/
   /*vector<vector<int>> mat = {
      {1,  2,  3,  4},
      {5,  6,  7,  8},
      {9, 10, 11, 12}
  };*/
   /*vector<vector<int>> mat = {
      {1,  2,  3,  4},
      {5,  6,  7,  8},
      {9, 10, 11, 12},
      {13, 14, 15, 16}
  };*/
  vector<vector<int>> mat = {{1}, {2}, {3}};
  print(spiralOrder(mat));

    }