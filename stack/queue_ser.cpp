
// FREEZE CODE BEGIN
#include <iostream>
#include <vector>
#include <string>
#include "Helper.h"
// FREEZE CODE END

// WRITE YOUR CODE HERE

struct Node{
    std::string info;
    Node*next;
    Node(std::string d) data(d)next(nullptr){};
};
// WRITE YOUR CODE HERE

class Queue{

};



// FREEZE CODE BEGIN
int main(int argc, char* argv[]) {
    Queue serviceQueue;
    std::vector<std::string> serviceRequests = Helper::parseArgs(argc, argv);
    
    for (const std::string& request : serviceRequests) {
        serviceQueue.enqueue(request);
    }
    
    std::cout << "Service Queue Status" << std::endl;
    std::cout << "--------------------" << std::endl;
    serviceQueue.printQueue();
    
    return 0;
}


// FREEZE CODE END