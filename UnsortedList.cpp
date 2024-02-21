#include "UnsortedList.h"
#include <iostream>
using namespace std;

template<class T>
UnsortedList<T>::UnsortedList() {
    head = tail = nullptr;
    length = 0;
}

template<class T>
void UnsortedList<T>::MakeEmpty() {
    while(head != nullptr)
    {
        Node* tmp = head;
        head = head->next;
        if(head == nullptr)
            tail = nullptr;
        else
            head->pre = nullptr;
        delete tmp;
        length--;
    }
}

template<class T>
bool UnsortedList<T>::IsFull() const {
    return false;
}

template<class T>
int UnsortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool UnsortedList<T>::Contains(T someItem) {
    if(head == nullptr)
        throw "Empty List";

    Node* nodePtr = head;
    while(nodePtr != nullptr)
    {
        if(nodePtr->data == someItem)
            return true;

        nodePtr = nodePtr->next;
    }

    return false;
}

template<class T>
void UnsortedList<T>::AddItem(T item) {
    Node* newNode = new Node;
    newNode->data = item;
    length++;
    //empty
    if(head == nullptr) {
        head = tail = newNode;
        return;
    }

    //beginning
    if(item < head->data)
    {
        newNode->next = head;
        head->pre = newNode;
        head = newNode;
    }
    else if(tail->data < item)
    {
        tail->next = newNode;
        newNode->pre = tail;
        tail = tail->next;
    }
    else
    {
        Node* pre = head;
        Node* nodePtr = head->next;
        while(nodePtr != nullptr)
        {
            if(item < nodePtr->data)
            {
                newNode->pre = pre;
                newNode->next = nodePtr;
                pre->next = newNode;
                nodePtr->pre = newNode;
                return;
            }
            pre = nodePtr;
            nodePtr = nodePtr->next;
        }
    }



}

template<class T>
void UnsortedList<T>::DeleteItem(T item) {
    if(head == nullptr)
        return;


    if(head->data == item)
    {
        Node* tmp = head;
        head = head->next;
        if(head == nullptr)
            tail = nullptr;
        else
            head->pre = nullptr;
        delete tmp;
        length--;
    }
    else if(tail->data == item)
    {
        Node* tmp = tail;
        tail = tail->pre;
        if(tail == nullptr)
            head = nullptr;
        else
            tail->next = nullptr;
        delete tmp;
        length--;
    }
    else
    {
        Node* pre = head;
        Node* nodePtr = head->next;
        while(nodePtr != nullptr)
        {
            if(nodePtr->data == item)
            {
                pre->next = nodePtr->next;
                nodePtr->next->pre = pre;
                delete nodePtr;
                length--;
                return;
            }
        }
    }
}
template<class T>
void UnsortedList<T>::print() {
    if(head == nullptr)
        return;

    Node* nodePtr = head;
    while(nodePtr != nullptr)
    {
        cout << nodePtr->data << ' ';
        nodePtr = nodePtr->next;
    }
    cout << endl;
    nodePtr = tail;
    while(nodePtr != nullptr)
    {
        cout << nodePtr->data << ' ';
        nodePtr = nodePtr->pre;
    }
    cout << endl;
}

template<class T>
void UnsortedList<T>::ResetIterator() {

}

template<class T>
T UnsortedList<T>::GetNextItem() {
    return T();
}
