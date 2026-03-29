#include <vector>
using namespace std;

class LinkedList {
 public:
  int value;
  LinkedList* next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList* head, int k) {
  LinkedList*node=head,*prev=nullptr;
  int counter=0,coun=0;
   if(counter-k<0)
   return;
  while(node!=nullptr)
    {
      counter++;
      node=node->next;
    }
  node=head;

  while(counter-k!=coun)
    {prev=node;
      coun++;
      node=node->next;
    }

 
   LinkedList*nodechange=(node->next!=nullptr)?node->next:nullptr;
   (prev!=nullptr)?prev->next=nodechange:{head->value=nodechange->value;
    head->next=nodechange->next;
    delete nodechange;
  
  
}
