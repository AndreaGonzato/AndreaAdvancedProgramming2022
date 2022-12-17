#pragma once


template <typename T>
class Node{
    public:
        T value;
        Node * next;

        Node(T v);
        void setNext(Node * n);
};

template <typename T>
Node<T>::Node(T val){
    value = val;
    setNext(nullptr);
}

template <typename T>
void Node<T>::setNext(Node * n){
    next = n;
}