#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node (){
        this->data = 0;
        this->next = nullptr;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// LinkedList class
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Print linked list
    void PrintLL() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Insert at head
    void insertAtHead(int data) {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    // Insert at tail
    void insertAtTail(int data) {
        Node* temp = new Node(data);
        if (head == nullptr) {
            head = temp;
            return;
        }

        Node* t = head;
        while (t->next != nullptr) {
            t = t->next;
        }
        t->next = temp;
    }

    void insertAtPosition(int Position , int data){

        Node* temp = new Node(data);
        if(Position == 0) {
            insertAtHead(data);
            return;
        }

        Node*t = head;
        while(Position-1 && t->next != nullptr  ){
            
            t = t->next;
            Position --;

        }
        if(t->next == nullptr){
            cout<<"Out of bound.. \n";
            return ;
        }

        temp->next = t->next;
        t->next = temp;
  

    }

    void deleteAtHead() {
        if(head == nullptr){
            cout<<"Linked list is under bound. \n";
            return;
        }
        Node* temp = head;

         
        head = temp->next;
    }

    void deleteAtTail(){
        Node * temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        temp->next = nullptr;

    }

    void deleteAtPosition(int position)
    { 
        if(position < 1){
            cout<<"invalid position";
            return;
        }
        else if(position == 1){
            deleteAtHead();
            return;
        }
        Node * temp = head;

        while(position-2 && temp->next != nullptr){
            temp = temp->next;
            position--;
        }
        if(temp->next == nullptr){
            cout<<"out of bound.. \n";
            return;
        }
        temp->next = temp->next->next;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LinkedList newList;

    Node* first = new Node(1);
    Node* second = new Node(10);
    Node* third = new Node(20);

    first->next = second;
    second->next = third;

    newList.head = first;

    cout << "Original Linked List: ";
    newList.PrintLL();


    cout << "After Insertion 5: ";

    newList.insertAtHead(5);
    newList.PrintLL();
    
    newList.insertAtTail(40);

    cout << "After Insertion at position 2: ";

    newList.insertAtPosition(2, 99);
    newList.PrintLL();

      cout << "After deletion at head ";

    newList.deleteAtHead();
    newList.PrintLL();
      cout << "After deletion at tail ";

    newList.deleteAtTail();


    newList.PrintLL(); 
    cout << "After deletion at position 2:    ";

    newList.deleteAtPosition(2);

    newList.PrintLL();
    return 0;
}
