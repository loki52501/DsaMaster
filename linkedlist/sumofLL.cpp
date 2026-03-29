using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* sumOfLinkedLists(LinkedList* linkedListOne, LinkedList* linkedListTwo) 
{
 LinkedList*first=linkedListOne;
 LinkedList*second=linkedListTwo;
 LinkedList*ans=new LinkedList(0);
 ans->next=new LinkedList(0);
 LinkedList*dummy=ans->next; 
 int carry=0; 
 
while(first!=nullptr || second!=nullptr)
   {
     if(first!=nullptr && second!=nullptr)
     {
       int val=carry+first->value+second->value;
       if(val/10==0)
       { 
         dummy->value=val;
         carry=0;
       }
       else
       {dummy->value=val%10;
        carry=val/10;
         }     
     first=first->next;
     second=second->next;
     }
     else if(first!=nullptr)
     {       
       int val=carry+first->value;
        if(val/10==0)
       { 
         dummy->value=val;
         carry=0;
       }
       else
       {dummy->value=val%10;
        carry=val/10;
         }  
       first=first->next;
     }
     else if(second!=nullptr)
     {
        int val=carry+second->value;
        if(val/10==0)
       { 
         dummy->value=val;
         carry=0;
       }
       else
       {dummy->value=val%10;
        carry=val/10;
         }  
       second=second->next;
     }
    
        cout<<dummy->value<<"\n";
    if( first==nullptr && second==nullptr && carry!=0)
    {
      dummy->next=new LinkedList(carry);
      break;
    }
    else if(first==nullptr && second==nullptr)
      break;
      
     dummy->next=new LinkedList(0);
   dummy=dummy->next;}
  
  return ans->next;
}