// FREEZE CODE BEGIN
#include <iostream>
#include <string>
#include <sstream>
// FREEZE CODE END
using namespace std;
// WRITE YOUR CODE HERE
struct DLLNode{
  DLLNode* next, *previous;
  string data;
  DLLNode(string datas) : next(nullptr), previous(nullptr),data(datas){};
};
class DoublyLinkedList{
  DLLNode* head,*tail;
  public:
  DoublyLinkedList():head(nullptr),tail(nullptr){}
  void insert(string transaction){
    DLLNode* newnode=new DLLNode(transaction);
    if(head==nullptr)
    {
      head =newnode;
      tail=newnode;
    }
    else{
      DLLNode*temp=tail;
      temp->next=newnode;
      newnode->previous=temp;
      tail=newnode;


    }
  }
  int total()
  {
    DLLNode*temp=head;
    int total=0;
    while(temp!=nullptr){
        string s=temp->data;
        if(s.substr(0,s.find(':'))=="Withdrawal"){
        int amount=stoi(s.substr(s.find('$')+1));
        total+=amount;}
        temp=temp->next;
    }
    return total;
  }



// FREEZE CODE BEGIN
void printList() {
    DLLNode* current = head;
    while (current != nullptr) {
        std::cout << "'" << current->data << "'";
        current = current->next;
        if (current != nullptr) {
            std::cout << " <-> ";
        }
    }
    std::cout << "\n";
}

};

int main(int argc, char* argv[]) {
    DoublyLinkedList transactionList;

    for (int i = 1; i < argc; i++) {
        transactionList.insert(argv[i]);
    }

    int total = transactionList.total();
    transactionList.printList();
    std::cout << "Total: $" << total << "\n";

    return 0;
}
