//
//  LinkedList.h
//
//  Laura Morgan Collaborated with Alecia Griffin
//

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <string>


using namespace std;

template <class T = int>
class Node {
public:
    Node();                                         // default constructor
    Node(const T& data, Node<T>* next = nullptr);   // donstructor
    T data;                                         // node data
    Node<T>* next;                                  // node next pointer
};

template <class T = int>
class LinkedList {
public:
    LinkedList();                                   // constructor
    ~LinkedList();                                  // destructor
    T deleteFromHead() throw (runtime_error);       // removes and returns content of head
    T deleteFromTail() throw (runtime_error);       // removes and returns content of tail
    void deleteNode(T data) throw (runtime_error);  // removes node with specified data
    void InsertToHead(T data);                      // insert node with data at the head
    void InsertToTail(T data);                      // insert node with data at the tail
    int getSize();                                  // returns size of linked list
    void print();                                   // prints linked list
private:
    Node<T>* head;                                  // head of linked list
};


/******* From here down is the content of the LinkedList.cpp file: ***********************/

 /* Implementation of Node */

 // default constructor
 template<class T>
 Node<T>::Node()
 {
 }
 
 // constructor
 template<class T>
 Node<T>::Node(const T& data, Node<T>* next)
 {
     this->data = data;
     this->next = next;
 }
 
 /* Implementation of linked list */

 // constructor
 template <class T>
 LinkedList<T>::LinkedList()
 {
     head = nullptr;
 }

 // destructor
 template <class T>
 LinkedList<T>::~LinkedList()
 {
    Node<T>* temp = head;
    while(head) {
    	head= head->next;
    	delete temp;
    	temp = head;
    }
 }

 template <class T>
 T LinkedList<T>::deleteFromHead() throw (runtime_error)
 {

    if (head == NULL) {
        throw runtime_error("LInkedList called with empty list");
    }
    
    Node<T>* temp;			// creates a new Node variable called temp
    temp = head;			// sets temp equal to head
    head = head->next;		// points head to the next node

    return temp->data;		// returns the value that was in head
    delete(temp);			// deletes the head node
 }


 template <class T>
 T LinkedList<T>::deleteFromTail() throw (runtime_error)
 {
    Node<T>* curNode = head;				// creates a new variable and sets it equal to head
    Node<T>* prevNode = NULL;				// equal to NULL so we know what node is the tail

    if (head == NULL) {
        throw runtime_error("LInkedList called with empty list");
    }

    if ((head-> next) == NULL) {			// if statement to check if there is only one node left 
        head = nullptr;
        return curNode->data;	
        delete curNode;						// deletes the node that is left
    }
    else {
        while (curNode -> next) {			// iterates through the nodes until we find the last node
            prevNode = curNode;
            curNode = curNode-> next;
        }

        if(prevNode) {
            prevNode-> next = NULL;			
            return curNode -> data;			// returns the value that was in the last node
            delete curNode;					// deletes the node
        }
    }
 }
 

 template <class T>
 void LinkedList<T>::deleteNode(T data) throw (runtime_error)
 {
        Node<T>* curNode = head;		// creates a new variable
        Node<T>* prevNode = NULL;


        if (head == NULL) {
            throw runtime_error("LInkedList called with empty list");
        }
        if (head->data == data) {		// determines if the value is the first node
            head = head->next;
        }
        else {
            while((curNode-> data) != data) {		// loops through as long as the node isn't the value we are looking for

            prevNode = curNode;
            curNode = curNode-> next;				// sets the variable to next node
            }
            prevNode-> next = prevNode-> next-> next;		// sets prevNode to correct node to take into account that the deleted node is no longer there
        }
            delete curNode;							// deletes the node 

 }
 

 template <class T>
 void LinkedList<T>::InsertToHead(T data)  // Given to us
 {
     Node<T> * newNode = new Node<T>(data, nullptr);
     
     if (head == nullptr)
         head = newNode;
     else
     {
         newNode->next = head;
         head = newNode;
     }
 }


 template <class T>
 void LinkedList<T>::InsertToTail(T data)
 {
     Node<T>* newNode = new Node<T>(data);  // creates a new node to keep track of the new head node
     newNode->data = data;					
     newNode->next = NULL;

     Node<T>* temp = head;					// creates a node and sets it equal to the head node

     if(temp != NULL) {						// loops until the last node
     	while(temp->next != NULL) {			
     		temp = temp->next;				// points to the next node
     	}
     	temp->next = newNode;				// sets the next node equal to newNode to keep track of the new head node
     } else {
     	head = newNode;						// inserts new node and sets the head to the new node
     }
 }


 template <class T>
 int LinkedList<T>::getSize()
 {
    Node<T>* temp = head;
    int count = 0;				// set up a counter to keep track of how many nodes there are 

    while(temp != NULL) {		// loops through nodes until it reaches the end
    	count = count + 1;		// increments counter
    	temp = temp->next;		// points to the next node
    }
    return count;				// returns the size
 }


 template <class T>
 void LinkedList<T>::print()  // Given
 {
     if (head == nullptr)
     {
         cout << "Linked list is empty" << endl;;
         return;
     }
     
     cout << head->data << " ";
     
     if (head->next == nullptr)
     {
         cout << endl;
         return;
     }
 
     Node<T>* currNode = head->next;
     Node<T>* prevNode = head;
 
     
     while (currNode->next != nullptr)
     {
         cout << currNode->data << " ";
         prevNode = currNode;
         currNode = currNode->next;
     }
 
     cout << currNode->data << endl;
     return;
 }
     
     
#endif /* LinkedList_h */