// FREEZE CODE BEGIN
#include <iostream>
#include <string>

class Node {
public:
    std::string data;
    Node* next;

    Node(const std::string& data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = nullptr;
    }
// FREEZE CODE END

void headandtaildelete(){
    Node*temp=head->next;
    delete head;
    head=temp;
    Node*prev;
    while(temp->next!=nullptr)
    {prev=temp;
        temp=temp->next;}
        prev->next=nullptr;
        delete temp;


}

// WRITE YOUR CODE HERE
 void deleteTarget(const std::string& target) {
  if(head->data==target)
  {
    Node*temp=head->next;
    delete head;

    head=temp;
    headandtaildelete();
  }
  else{
    Node* temp=head;
    Node*prev;
    while(temp->next!=nullptr && temp->data!=target)
    { prev=temp;
        temp=temp->next;}
        if(temp->next==nullptr)
        {
            prev->next=nullptr;
            delete temp;
        }
        else{
            prev->next=temp->next;
            delete temp;
        }
  headandtaildelete();
  }
 }



// FREEZE CODE BEGIN
    void printList() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

void makeList(SinglyLinkedList& list, char* values[], int size) {
    for (int i = 0; i < size; ++i) {
        Node* newNode = new Node(values[i]);
        if (list.head == nullptr) {
            list.head = newNode;
        } else {
            Node* temp = list.head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

int main(int argc, char* argv[]) {
    SinglyLinkedList list;
    // argv[0] is the program name, so actual values start at argv[1]
    // Pass argv+1 to skip program name, argc-1 for the count
    makeList(list, argv + 1, argc - 1);
    list.deleteTarget(argv[argc - 1]);  // Last argument is the target
    list.printList();
    return 0;
}


// FREEZE CODE END
