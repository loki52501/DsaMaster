#include<stack>
#include<map>
#include<iostream>
using namespace std;

bool balancedBrackets(string str) {
  stack<char> stacker;
  map<char,char> opp={{']','['},{'}','{'},{')','('}};
  int size=str.size();
  
  for(int i=0; i<size; i++) {
    // Only push opening brackets
    if(str[i]=='(' || str[i]=='[' || str[i]=='{') {
      stacker.push(str[i]);
    }
    // Handle closing brackets
    else if(str[i]==')' || str[i]==']' || str[i]=='}') {
      // If stack is empty, unmatched closing bracket
      if(stacker.empty()) {
        return false;
      }
      // Check if it matches the top
      if(stacker.top() != opp[str[i]]) {
        return false;
      }
      stacker.pop();
    }
    // Ignore all other characters
  }
  
  return stacker.empty();
}
