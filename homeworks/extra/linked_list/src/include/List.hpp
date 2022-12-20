#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Node.hpp"

struct Exception
{
    std::string message;
    Exception(std::string m) : message{std::move(m)} {};
};

template <typename T>
class List
{
private:
    Node<T> *getINode(int index) const;
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    int size = 0;

public:
    List(Node<T> *firstNode);
    List(T firstValue);
    List();
    List(const List &l1);
    ~List();

    void push(const T newVal);
    void replaceIElement(int index, const T newVal);
    T getIElement(int index) const;
    void loadFromFile(std::string fileName);
    T remove();
    void print() const;
    int getSize() const { return size; };
};

template <typename T>
List<T>::List() {}

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

// copy constructor
template <typename T>
List<T>::List(const List<T> &l1)
{
    if (l1.size == 0)
    {
        return;
    }

    for (int i = 0; i < l1.size; i++)
    {
        T iVal = l1.getIElement(i);
        this->push(iVal);
    }
    
    size = l1.size;
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
        head = nullptr;
        tail = nullptr;
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
    if (size == 0)
    {
        head = newNode;
        tail = head;
        tail->next = nullptr;
    }
    else
    {
        tail->next = newNode;
    }
    tail = newNode;

    size += 1;
}

template <typename T>
void List<T>::replaceIElement(int index, const T newVal)
{
    if (index < 0)
    {
        throw Exception("Index need to be positive");
    }
    if (index >= size)
    {
        throw Exception("Index need to less than the size of the list to replace an element");
    }

    Node<T> *node = getINode(index);
    node->value = newVal;
}

template <typename T>
void List<T>::print() const
{
    if (head == nullptr)
    {
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
Node<T> *List<T>::getINode(int index) const
{
    Node<T> *nodeI = head;

    for (int i = 1; i <= index; i++)
    {
        nodeI = nodeI->next;
    }

    return nodeI;
}

template <typename T>
T List<T>::getIElement(int index) const
{
    return getINode(index)->value;
}

template <typename T>
T List<T>::remove()
{
    // remove the last element in the list

    if (size == 0)
    {
        throw Exception("List is already empty, you can not remove an element");
    }

    T output = tail->value;

    if (size == 1)
    {
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

template <typename T>
void List<T>::loadFromFile(std::string fileName)
{
    std::ifstream file(fileName);
    if (file)
    {
        int elements = 0;
        file >> elements;
        if (elements < 0)
        {
            throw Exception("You can not load a List with a negative size. (The first element of the list need to be the size of it!)");
            return;
        }

        for (int i = 0; i < elements; i++)
        {

            T temp;
            file >> temp;
            push(temp);
        }
    }
    else
    {
        file.close();
        throw Exception("File " + fileName + " not found");
    }

    file.close();
}