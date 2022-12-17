#pragma once

#include <iostream>
#include "Node.hpp"

template <typename T>
class List
{
private:

    Node<T> *getINode(int index);

public:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    int size = 0;

    List(Node<T> *firstNode);
    List(T firstValue);
    ~List();

    void push(const T newVal);
    T getIElement(int index);
    T remove();
    void print();
    int getSize() { return size; };
};

template <typename T>
List<T>::List(Node<T> *firstNode)
{
    head = firstNode;
    tail = head;
    size = 1;
}

template <typename T>
List<T>::List(T firstValue)
{
    head = new Node(firstValue);
    tail = head;
    size = 1;
}

template <typename T>
List<T>::~List()
{
    if (head == nullptr)
    {
        tail = nullptr;
        return;
    }

    if (head->next == nullptr)
    {   
        delete head;
        return;
    }

    Node<T> *node = head;

    while (node->next != nullptr)
    {
        Node<T> *nextNode = node->next;
        delete node;
        node = nextNode;
    }

    delete node;
}

template <typename T>
void List<T>::push(const T newVal)
{
    Node<T> *newNode = new Node(newVal);
    tail->next = newNode;
    tail = newNode;
    size += 1;
}

template <typename T>
void List<T>::print()
{
    if(head == nullptr){
        std::cout << "Empty List:{}" << std::endl;
        return;
    }

    Node<T> *nodeToPrint = head;

    std::cout << "List:{";

    while (nodeToPrint != tail)
    {
        std::cout << nodeToPrint->value << " ";
        nodeToPrint = nodeToPrint->next;
    }

    std::cout << tail->value << "}" << std::endl;
}

template <typename T>
Node<T> *List<T>::getINode(int index)
{
    Node<T> *nodeI = head;

    for (int i = 1; i <= index; i++)
    {
        nodeI = nodeI->next;
    }

    return nodeI;
}

template <typename T>
T List<T>::getIElement(int index)
{
    return getINode(index)->value;
}

template <typename T>
T List<T>::remove()
{
    // remove the last element in the list

    if(size == 0){
        std::cout << "ERROR: List is already empty, you can not remove an element" << std::endl;
        throw 505;
    }

    T output = tail->value;

    if(size == 1){
        delete tail;
        tail = nullptr;
        head = nullptr;
        size -= 1;

        return output;
    }

    if (size > 1)
    {

        Node<T> *second_last = getINode(size - 2);

        second_last->next = nullptr;

        delete tail;

        tail = second_last;

        size -= 1;

        return output;

    }

    return output;
}