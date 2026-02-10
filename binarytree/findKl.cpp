/*Find Kth Largest Value In BST
☆
Write a function that takes in a Binary Search Tree (BST) and a positive integer k and returns the kth largest integer contained in the BST.
You can assume that there will only be integer values in the BST and that k is less than or equal to the number of nodes in the tree.
Also, for the purpose of this question, duplicate integers will be treated as distinct values. In other words, the second largest value in a BST containing values {5, 7, 7} will be 7-not 5
Each BST node has an integer value, a left child node, and a
right child node. A node is said to be a valid BST node if and only if it satisfies the BST property: its value is strictly greater than the values of every node to its left its value is less than or equal to the values of every node to its right; and its children nodes are either valid BST nodes themselves or None / null.
*/
#include<iostream>
#include<stack>
#include<vector>
#include<cassert>
using namespace std;

// This is an input class. Do not edit.
class BST {
 public:
  int value;
  BST* left = nullptr;
  BST* right = nullptr;

  BST(int value) { this->value = value; }
};
void desce(BST* , vector<int>&) ;
void desce_stack(BST* , vector<int>&);
int findKthLargestValueInBst(BST* tree, int k) {
  vector<int>res;
  desce_stack(tree,res);
return (res.size()>0)?res[k-1]:-1;}
void desce(BST* tree, vector<int>&res){
    if(tree==nullptr)
    return;
    else
    {
        desce(tree->right,res);
        res.push_back(tree->value);
        desce(tree->left,res);
    }
}
void desce_stack(BST* tree, vector<int>&res){
    stack<BST*> s;
    BST* curr=tree;
    s.push(curr);
     if(tree == nullptr)
        return;
    while(!s.empty()){
       while(curr!=nullptr){
     
        curr=curr->right;
           s.push(curr);
       }
       curr=(s.top())->left;
       res.push_back(s.top()->value);
       s.pop();
     
    }

}

int main(){
 auto root = new BST(15);
      root->left = new BST(5);
      root->left->left = new BST(2);
      root->left->left->left = new BST(1);
      root->left->left->right = new BST(3);
      root->left->right = new BST(5);
      root->right = new BST(20);
      root->right->left = new BST(17);
      root->right->right = new BST(22);
      root->right->left->right = new BST(19);
      int k = 3;
      int expected = 19;
      auto actual = findKthLargestValueInBst(root, k);
      cout<<actual<<endl;
      assert(expected == actual);
}