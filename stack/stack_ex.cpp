// FREEZE CODE BEGIN
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// A Node represents a single element in the stack
class Node {
public:
    std::string data;
    Node* next;

    Node(const std::string& data) : data(data), next(nullptr) {}
};

// Stack class implementing a stack using a linked list
class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

// FREEZE CODE END
void parseAlerts(const std::vector<std::string>& alerts)
{
    for(auto alert:alerts){
        if(alert[0]=='@')
        {
         push(alert);
        }
    }
}
void push(const std::string& data) 
{    Node*newNode=new Node(data);

    if(top==nullptr)
     {top=newNode;
        return;}
    
    Node*temp=top;
    top=newNode;
    top->next=temp;
}
void printStack() 

// WRITE YOUR CODE HERE
{
    if(top==nullptr)
    {std::cout<<"Incident Stack Empty: true"<<std::endl<<"No incidents to report."<<std::endl;
        return;}
    else
    std::cout<<"Incident Stack Empty: false"<<std::endl;
    Node*temp=top;
    while(temp!=nullptr)
    {
    std::cout<<temp->data<<std::endl;
    temp=temp->next;
    }
}




// FREEZE CODE BEGIN
    // Method to check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }
};

// Function to parse command line arguments into incident strings
class PushStack {
public:  
std::vector<std::string> parseArgs(int argc, char* argv[]) {
    std::vector<std::string> incidents;
    std::stringstream sb;

    for (int i = 1; i < argc; ++i) { // Start from 1 to skip program name
        if (std::string(argv[i]) != ":") {
            sb << argv[i] << " ";
            if (i + 1 == argc) {
                incidents.push_back(sb.str());
            }
        } else {
            incidents.push_back(sb.str());
            sb.str("");
            sb.clear();
        }
    }

   return incidents;
  }
};

// Main function to demonstrate the Stack operations
int main(int argc, char* argv[]) {
    Stack incidentStack;
    PushStack parse;
    std::vector<std::string> incidents = parse.parseArgs(argc, argv);
    incidentStack.parseAlerts(incidents);
    std::cout << "Incident Stack Empty: " << std::boolalpha << incidentStack.isEmpty() << std::endl;
    incidentStack.printStack();
    return 0;
}
// FREEZE CODE END
