//
//  LinkedList.h
//
//  Laura Morgan Collaborated with Alecia Griffin
//

#ifndef Problem3c_h
#define Problem3c_h

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

template <class T = char>
class QueueFromList {
public: 
    QueueFromList();            // constructor
    ~QueueFromList();           // destructor
    void enqueue(T data);       // places characters into queue
    T dequeue();                // removes character from queue
    bool isEmpty();             // determines if the queue is empty
private:
    Node<T>* head;
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

    Node<T>* temp;
    temp = head;
    head = head->next;

    return temp->data;
    delete(temp);
 }


 template <class T>
 T LinkedList<T>::deleteFromTail() throw (runtime_error)
 {
    Node<T>* curNode = head;
    Node<T>* prevNode = NULL;

    if (head == NULL) {
        throw runtime_error("LInkedList called with empty list");
    }

    if ((head-> next) == NULL) {
        head = nullptr;
        return curNode->data;
        delete curNode;
    }
    else {
        while (curNode -> next) {
            prevNode = curNode;
            curNode = curNode-> next;
        }

        if(prevNode) {
            prevNode-> next = NULL;
            return curNode -> data;
            delete curNode;
        }
    }
 }
 

 template <class T>
 void LinkedList<T>::deleteNode(T data) throw (runtime_error)
 {
        Node<T>* curNode = head;
        Node<T>* prevNode = NULL;


        if (head == NULL) {
            throw runtime_error("LInkedList called with empty list");
        }
        if (head->data == data) {
            head = head->next;
        }
        else {
            while((curNode-> data) != data) {

            prevNode = curNode;
            curNode = curNode-> next;
            }
            prevNode-> next = prevNode-> next-> next;
        }
            delete curNode;

 }
 

 template <class T>
 void LinkedList<T>::InsertToHead(T data)
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
     Node<T>* newNode = new Node<T>(data);
     newNode->data = data;
     newNode->next = NULL;

     Node<T>* temp = head;

     if(temp != NULL) {
     	while(temp->next != NULL) {
     		temp = temp->next;
     	}
     	temp->next = newNode;
     } else {
     	head = newNode;
     }
 }


 template <class T>
 int LinkedList<T>::getSize()
 {
    Node<T>* temp = head;
    int count = 0;

    while(temp != NULL) {
    	count = count + 1;
    	temp = temp->next;
    }
    return count;
 }


 template <class T>
 void LinkedList<T>::print()
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


// _____________implementation of Queue_______________________________________//

//constructor
template <class T>
QueueFromList<T>::QueueFromList()
{
    head = nullptr;
}

//destructor
template <class T>
QueueFromList<T>::~QueueFromList()
{
    Node<T>* temp = head;
    while(head) {
        head= head->next;
        delete temp;
        temp = head;
    }
}

//queue
template <class T>
void QueueFromList<T>::enqueue(T data)     // similar to insert to tail
{

    Node<T>* newNode = new Node<T>(data);
     newNode->data = data;
     newNode->next = NULL;

     Node<T>* temp = head;

     if(temp != NULL) {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
     } else {
        head = newNode;
     }
}

//dequeue
template <class T>
T QueueFromList<T>::dequeue()          // similar to delete from head
{

    Node<T>* temp = head;
    head = head -> next;
    return temp->data;
    delete temp;
}

//isEmpty
template <class T>
bool QueueFromList<T>::isEmpty()
{
    if (head == nullptr){       // if the head is NULL then the queue is empty
        return true;
    }
}
#endif /* LinkedList_h */