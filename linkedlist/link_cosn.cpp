using namespace std;

class Node {
 public:
  int value;
  Node* prev;
  Node* next;

  Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
 public:
  Node* head;
  Node* tail;

  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }
  void setHead(Node* node) {
    if (node == head) return;
    if (head == nullptr) { head = node; tail = node; return; }
    remove(node);
    node->next = head;
    head->prev = node;
    node->prev = nullptr;
    head = node;
  }

  void setTail(Node* node) {
    if (node == tail) return;
    if (tail == nullptr) { head = node; tail = node; return; }
    remove(node);
    node->prev = tail;
    tail->next = node;
    node->next = nullptr;
    tail = node;
  }
void insertBefore(Node* node, Node* nodeToInsert) {
    remove(nodeToInsert);
 if (node == head) {
          setHead(nodeToInsert);
      } else {
          node->prev->next = nodeToInsert;
          nodeToInsert->prev = node->prev;
          nodeToInsert->next = node;
          node->prev = nodeToInsert;
      }
  }

  void insertAfter(Node* node, Node* nodeToInsert) {
    remove(nodeToInsert);
 if (node == tail) {
          setTail(nodeToInsert);
      } else {
          node->next->prev = nodeToInsert;
          nodeToInsert->next = node->next;
          nodeToInsert->prev = node;
          node->next = nodeToInsert;
      }
  }

void insertAtPosition(int position, Node* nodeToInsert) {
    // Find the node currently at 'position' BEFORE removing anything
    Node* nodeAtPosition = head;
    int count = 1;
    while (nodeAtPosition != nullptr && count < position) {
      nodeAtPosition = nodeAtPosition->next;
      count++;
    }
    // If nodeToInsert is already at that position, nothing to do
    if (nodeAtPosition == nodeToInsert) return;
    remove(nodeToInsert);
    if (nodeAtPosition == nullptr) {
      setTail(nodeToInsert);
    } else if (nodeAtPosition == head) {
      setHead(nodeToInsert);
    } else {
      nodeAtPosition->prev->next = nodeToInsert;
      nodeToInsert->prev = nodeAtPosition->prev;
      nodeToInsert->next = nodeAtPosition;
      nodeAtPosition->prev = nodeToInsert;
    }
  }

  void removeNodesWithValue(int value) {
    Node* curr = head;
    while (curr != nullptr) {
      Node* next = curr->next;
      if (curr->value == value) {
        remove(curr);
        delete curr;
      }
      curr = next;
    }
  }

  void remove(Node* node) {
    if (node == head) head = node->next;
    if (node == tail) tail = node->prev;
    if (node->prev != nullptr) node->prev->next = node->next;
    if (node->next != nullptr) node->next->prev = node->prev;
    node->prev = nullptr;
    node->next = nullptr;
  }

  bool containsNodeWithValue(int value) {
    Node* curr = head;
    while (curr != nullptr) {
      if (curr->value == value) return true;
      curr = curr->next;
    }
    return false;
  }
};
