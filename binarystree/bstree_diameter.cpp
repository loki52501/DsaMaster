#include<iostream>
#include<vector>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

int binaryTreeDiameter(BinaryTree* tree) {
unordered_map<BinaryTree*,int>height;
return helper(tree,height);
}
int helper(BinaryTree*tree, unordered_map<BinaryTree*,int>height)
{
 if(tree==nullptr)
 return 0;
 height[tree]=1+max(helper(tree->left,height),helper(tree->right,height));
 return height[tree] +(tree->left!=nullptr && tree->right!=nullptr)?max(height[tree->left],height[tree->right]):0;
}
int main()
{
      BinaryTree* root = new BinaryTree(1);
      root->left = new BinaryTree(3);
      root->left->left = new BinaryTree(7);
      root->left->left->left = new BinaryTree(8);
      root->left->left->left->left = new BinaryTree(9);
      root->left->right = new BinaryTree(4);
      root->left->right->right = new BinaryTree(5);
      root->left->right->right->right = new BinaryTree(6);
      root->right = new BinaryTree(2);
      int expected = 6;
      int actual = binaryTreeDiameter(root);
      cout<<expected<<", "<<actual;
}
