#include<iostream>
#include "node.h"
using namespace std;
class AVLTree{
    Node* root;
    Node* minValueNode(Node*node){
        Node*minv=node;
        while(minv->left!=nullptr)
        {
                    cout<<endl<<" figuring out the smallest value:"<<minv->value<<endl;

            minv=minv->left;
        }
        return minv;
    }
    Node* insert(Node* node, int value){
        if(node==nullptr)
        return new Node(value);
        if(value<node->value)
        {
            node->left=insert(node->left,value);
        }
        else if(value>node->value)
        node->right=insert(node->right,value);
        else
        return node;

        updateheight(node);
        return rebalance(node);
    }
    Node* rebalance(Node*node){
        int balanceFactor=this->balanceFactor(node);
        //left heavy
        if(balanceFactor>1)
        {
            if(this->balanceFactor(node->left)>0)
            node=rotateRight(node);
            else{
                node->left=rotateLeft(node->left);
                node=rotateRight(node);
                
            }
        }
        else if(balanceFactor<-1){
            if(this->balanceFactor(node->right)<0)
            node=rotateLeft(node);
            else {
                // Case 4: Right-Left
                node->right = rotateRight(node->right);
                node = rotateLeft(node);
            }
        }
        return node;
    }
    void preOrder(Node* node) {
        if (node != nullptr) {
            std::cout << node->value << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    int height(Node*node){
        return node ? node->height :-1;
    }
    void updateheight(Node*node){
        int leftChildHeight=height(node->left);
        int rightChildHeight=height(node->right);
        node->height=max(leftChildHeight,rightChildHeight)+1;
    }
    Node* rotateLeft(Node*node){
        if(!node||!node->right){
            return node;
        }
        Node*rightChild=node->right;
        node->right=rightChild->left;
        rightChild->left=node;
        updateheight(node);
        updateheight(rightChild);
        return rightChild;
    }
    Node* rotateRight(Node*node){
        if(!node||!node->left){
            return node;
        }
        Node*leftChild=node->left;
        node->left=leftChild->right;
        leftChild->right=node;
        updateheight(node);
        updateheight(leftChild);
        return leftChild;
    }
    int balanceFactor(Node* node){
        return height(node->left)-height(node->right);
    }
    Node* deleteNode(Node* root,int value){
        if(root==nullptr)
        return root;
        if(value<root->value){
            cout<<endl<<" came here with:"<<root->value<<endl;
            root->left=deleteNode(root->left,value);}
        else if(value>root->value){
            root->right=deleteNode(root->right,value);
        }
        else{
            Node*curr=root;
            cout<<"came here oce before;"<<root->value<<endl;
            if(root->left==nullptr && root->right==nullptr)
            {cout<<"ccame here once"<<endl;
                return nullptr;}
            else if(root->left==nullptr)
            return root->right;
            else if(root->right==nullptr)
            return root->left;
            else{
                cout<<endl<<" minimum value in which subtree: "<<root->right->value<<endl;
                Node* temp = minValueNode(root->right);
                cout<<endl<<" here is the exchange value"<<temp->value<<endl;
                // Copy the in-order successor's value
                root->value = temp->value;
                // Delete the in-order successorr
                root->right = deleteNode(root->right, temp->value);
            }
      
        }
          updateheight(root);
          return rebalance(root);
    }
    public: 
    AVLTree():root(nullptr){}
    void insert(int value){
        root=insert(root,value);

    }
    void preOrder(){
    preOrder(root);
    }
    void deletevalue(int value){
        root=deleteNode(root,value);
    }

};
int main() {
    AVLTree tree;

    // Insert nodes
    tree.insert(10);
    tree.insert(8);
    tree.insert(20);
    tree.insert(5);
    tree.insert(9);
    tree.insert(12);
    tree.insert(30);
    tree.insert(40);
        tree.insert(50);

     

    // Rotate and print tree
    std::cout << "Before rotation: ";
    tree.preOrder();
    tree.deletevalue(10);
    std::cout << "\nAfter rotation: ";
    tree.preOrder();

    return 0;
}

