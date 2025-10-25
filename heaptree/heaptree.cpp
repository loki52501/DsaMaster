#include <vector>
#include<iostream>
#include<math.h>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.

class MinHeap {
 public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(vector); }

  vector<int> buildHeap(vector<int>& vector) {
 int firstparent=(vector.size()-1)/2;
        cout<<firstparent<<"\n";
    for(int i=firstparent+1;i>=0;i--)
siftDown(i,vector.size(),vector);
        
     
    return vector;
  }

  void siftDown(int currentIdx, int endIdx, vector<int>& heap) {
    int child1=currentIdx*2+1;
    int child2=currentIdx*2+2;
    while(child1<endIdx)
      {
        int psi=0;
        if(child2<endIdx && heap[child2]<heap[child1])
          psi=child2;
       else
          psi=child1;
        cout<< psi<< " "<<currentIdx<<" "<<"\n";
       if(heap[psi]<heap[currentIdx])
       {
         swap(psi,currentIdx,heap);
       }
       currentIdx=psi;
        child1=currentIdx*2+1;
       child2=currentIdx*2+2;
      }
  }

  void siftUp(int currentIdx, vector<int>& heap) {
    int curr=currentIdx;
    int parent = floor((curr-1)/2);
    while(heap[curr]<heap[parent])
      {
        swap(curr,parent,heap);
        curr=parent;
        parent=floor((curr-1)/2);
      }
  }

  int peek() {
    // Write your code here.
    return heap[0];
  }

  int remove() {
    int top=heap[0];
     swap(0,heap.size()-1,heap);

    siftDown(0,heap.size()-1,heap);
    heap.erase(heap.end());
    return top;
  }

  void insert(int value) {
    heap.push_back(value);
    siftUp(heap.size()-1,heap);
  }
void swap (int curr,int swapindex,vector<int>&heap)
{
  int temp=heap[curr];
  heap[curr]=heap[swapindex];
  heap[swapindex]=temp;
}
friend ostream& operator<<(ostream&,MinHeap);
};

ostream& operator<<(ostream& co,MinHeap h)
{ 
    vector<int>h1=h.heap;
    for(int i=0;i<h1.size();i++)
    co<<h1[i]<<" ";
    co<<"\n";
    co<<"Finish \n";
    return co;
}

int main()
{
    MinHeap hq({48, 12, 24, 7, 8, -5, 24, 391, 24, 56, 2, 6, 8, 41});
    hq.remove();
    cout<<hq;

return 0;
}