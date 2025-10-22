#include <unordered_map>
#include<iostream>
using namespace std;

// Do not edit the class below except for the
// populateSuffixTrieFrom and contains methods.
// Feel free to add new properties and methods
// to the class.
class TrieNode {
 public:
  unordered_map<char, TrieNode*> children;
};

class SuffixTrie {
 public:
  TrieNode* root;
  char endSymbol;

  SuffixTrie(string str) {
    this->root = new TrieNode();
    this->endSymbol = '*';
    this->populateSuffixTrieFrom(str);
  }

  void populateSuffixTrieFrom(string str) {
    unordered_map<char,TrieNode> s;
 for(int i=0;i<str.size();i++)
   {TrieNode *node=root;
    for(int j=i;j<str.size();j++)
      {
        if(!((node->children).count(str[j])>0))
          node->children[str[j]]=new TrieNode();
        node=node->children[str[j]];
          }
    node->children[endSymbol]=nullptr;
   }
  }

  bool contains(string str) {
    TrieNode *node=root;
    int tracker=0;
   for(int i=0;i<str.size();i++)
     {
       if(node->children.count(str[i])>0)
       {
         tracker++;
         node=node->children[str[i]];

       }
     }
   return node->children.count(endSymbol) > 0;
  }
};
