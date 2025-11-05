#include <optional>
#include<unordered_map>
#include<iostream>
using namespace std;

// Do not edit the class below except for
// the constructor, push, pop, peek, and
// isEmpty methods. Feel free to add new
// properties and methods to the class.

class UnionFind {
unordered_map<int,int>ar;
unordered_map<int,int>rank;
 public:

  void createSet(int value) {

    ar[value]=value;
    rank[value]=1;
  }

optional<int> find(int value) {
   if(ar.count(value)==0)
     return nullopt;
  while(value!=ar[value])
    value=ar[value];
  return value;
}

  void createUnion(int valueOne, int valueTwo) {
  
    if(!ar.count(valueOne) || !ar.count(valueTwo))
    return;
    int a=*(find(valueOne));
    int b=*(find(valueTwo));
    if(rank[a]>rank[b])
    {
      int temp=a;
      a=b;
      b=temp;
    }
    ar[a]=b;
    if(rank[a]==rank[b])
    rank[b]++;}
};
