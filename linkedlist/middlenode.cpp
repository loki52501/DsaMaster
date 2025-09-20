#include<iostream>
using namespace std;
// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* middleNode(LinkedList* linkedList) {
  // Write your code here.
  int i=0,j=0;
  LinkedList* tr;
  tr=linkedList;
  while(linkedList)
    {
      i++;
      linkedList=linkedList->next;
    }
  linkedList=tr;
  cout<<i;
  while(linkedList)
    {
      if(floor(i/2)==j)
        return linkedList;
     else
        linkedList=linkedList->next;
j++;    }
  return nullptr;
}