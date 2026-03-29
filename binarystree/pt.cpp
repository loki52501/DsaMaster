#include<iostream>
#include<vector>
using namespace std;

// This is an input class. Do not edit.
class BST {
 public:
  int value;
  BST* left = nullptr;
  BST* right = nullptr;

  BST(int value) { this->value = value; }
};
BST* helper(vector<int>& pre, int& idx, int lb, int ub)
{
  if(idx >= pre.size() || !(pre[idx] > lb && pre[idx] < ub))
    return nullptr;
  BST* tree = new BST(pre[idx]);
  idx++;
  tree->left = helper(pre, idx, lb, pre[idx-1]);
  tree->right = helper(pre, idx, pre[idx-1], ub);
  return tree;
}
BST* reconstructBst(vector<int> preOrderTraversalValues) {
  BST*root=new BST(preOrderTraversalValues[0]);
  
  return helper(preOrderTraversalValues,0,INT_MIN,INT_MAX);
}
int main()
{
    vector<int>array{10, 4, 2, 1, 5, 17, 19, 18};
    BST* root=reconstructBst(array);
}