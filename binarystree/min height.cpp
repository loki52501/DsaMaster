#include<iostream>
using namespace std;

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

BST* minHeightBst(vector<int> array) {

  return constructTree(array,0,array.size()-1);
}

BST* constructTree(vector<int> array, int begin, int end)
{
  if(begin>end) return nullptr;
  int mid=(begin+end)/2;
  BST* tree=new BST(array[mid]);
  tree->left=constructTree(array,begin,mid-1);
  tree->right=constructTree(array,mid+1,end);
  return tree;
}
