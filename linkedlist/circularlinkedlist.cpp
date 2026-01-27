#include <iostream>
// FREEZE CODE BEGIN
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
// FREEZE CODE END
class CircularLinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;

    public: void insert(int data) {
        Node* newNode = new Node(data);
        if(head==nullptr)
        {
            head=newNode;
            tail=newNode;
            tail->next=head;
        }
        else{
          Node* temp=tail;
          temp->next=newNode;
          tail=newNode;
          tail->next=head;
        }
    }

    public: void display() {
        if(head != nullptr) {
            std::cout << "Head: " << head->data << std::endl;
            std::cout << "Tail: " << tail->data << std::endl;
            std::cout << "Nodes: ";
            Node* current=head;
           do {
            std::cout << current->data << " ";
            current = current->next;
        } while(current != head);  // Stop when we loop back to head
        std::cout << std::endl;
        }
    }
};
// WRITE YOUR CODE HERE



// FREEZE CODE BEGIN
int main(int argc, char* argv[]) {
    CircularLinkedList cList;

    cList.insert(std::stoi(argv[1]));
    cList.insert(std::stoi(argv[2]));
    cList.insert(std::stoi(argv[3]));
    cList.insert(std::stoi(argv[4]));

    cList.display();
    return 0;
}
// FREEZE CODE END
