#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *first = nullptr;

void Insert(struct Node* &first , int x)
{
    Node *t = new Node();
    
    t->data = x; 
    t->next = nullptr;

    if(first == nullptr)
    {
        first = t;
        
    }
    else{
        Node *p = first;
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = t;
    }  



}

void InsertionAtBegining(Node * &first , int x){
    Node *temp = new Node();
    temp->data = x; 
    temp->next = nullptr; 
  Node  *last = first;
  
  temp->next = first;
  first = temp;
}


void InsertionAtLast(Node * &first , int x){
    Node *temp = new Node();
    temp->data = x; 
    temp->next = nullptr; 

    if(first == nullptr)
    {
        first = temp;
    }

    Node *last = first;
    while(last->next != nullptr){
        last = last->next;

    }
    last->next = temp;
}




void Display(struct Node *first )
{
    
    while (first)
    {
        cout<<first->data<<" ";
        first = first->next;
    }
    cout<<"NULL"<<endl;
    
}

void RdisplayLL(Node *first ){
    
    if(first->next == nullptr)
    {
        return;
    }
    cout<<first->data<<",";
    RdisplayLL(first->next);
}

// for displaying linkedlist in reverse order.
void RRdisplayLL(Node *first ){
    
    if(first == nullptr)
    {   
        cout<<"Null ,";
        return;
    }
    RRdisplayLL(first->next);
    cout<<first->data<<",";

}


void createLL( int A[], int n)
{
     first = new Node();
     first->data = A[0];
     first->next = nullptr;

     Node *last = first;
    for(int i = 1 ; i<n; i++){
        Node *Temp = new Node();
        Temp->data = A[i];
        Temp->next = nullptr;

        last->next = Temp;
        last = Temp;

    }
}

int countNodeinLL(Node *p)
{
    int count = 0;
    while(p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int RcountNodeinLL(Node *p)
{
    

    if(p == nullptr)
    {
        return 0;
    }
    return   RcountNodeinLL(p = p->next) + 1 ;
}

int NodeDataSum(Node *p){

    int sum = 0 ; 
    while(p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}


int RNodeDataSum(Node *head)
  {
    // int sum = 0 ;
    if(head == 0)
          return 0;
    return head->data + RNodeDataSum(head->next);
  }


int MaxinLL(Node *p){

    int max = INT_MIN;
    while(p)
    {
        if(p->data > max){
            max = p->data;
        }
        p = p->next;
    }

    return max;

}


int MininLL(Node *p){

    int min = INT_MAX;
    while(p)
    {
        if(p->data < min){
            min = p->data;
        }
        p = p->next;
    }

    return min;

}

bool SerchLL(Node *p,int key)
{
   while(p)
   {
    if(p->data == key)
    {
        return true;
    }
    p = p->next;
   }
   return false;
}


void InsertAtPosition(Node* &first ,int position, int x){

    if(position > countNodeinLL(first)){
        return ;
    }


    Node *temp = new Node();
    temp->data = x;
    temp->next = nullptr;

    Node *p, *last;
    
    last = first;

    int count = 0;
    
    while(count < position - 1 )
    {   
        last = last->next;
        count ++;
    }
   temp->next = last->next;
   last->next = temp;


}


int main()
{ 
    //Node *first = nullptr;  // first = head.

    

    int A[] = {4,5,15,25,211,555};
    int n = sizeof(A) / sizeof(A[0]);
    
    createLL(A,n);

    // Insert(first,5);
    // Insert(first,15);
    // Insert(first,25);
    // Insert(first,35);
    // Insert(first,45);


   cout<<"Printing Linked list"<<endl;

   InsertionAtBegining(first, 44);
   InsertionAtLast(first,77);
    Display(first);

    

   //RdisplayLL(first);

//    cout<<"Printing Linked list in reverse order "<<endl;

//    RRdisplayLL(first);
    int check = SerchLL(first,5);
    if(check){
                 cout<<"eliment is present"<<endl;

    }
    else{
                 cout<<"eliment is not present"<<endl;

    }

    cout<<"Total number of node is "<<RcountNodeinLL(first)<<endl;

    cout<<"Total sum of all number is "<<RNodeDataSum(first)<<endl;
 
    cout<<"Maximum  number in NODE is "<<MininLL(first)<<endl;


    InsertAtPosition(first,55,324);
    Display(first);

    return 0;
}