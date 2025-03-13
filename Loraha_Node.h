#ifndef LORAHA_NODE_H
#define LORAHA_NODE_H

template <typename T>
class Node{
    public:
        T data;
        Node<T>* previous;
        Node<T>* next;

        Node(T data){
            this->data = data;
            this->previous = nullptr;
            this->next = nullptr;
        }

        T getData(){
            return this->data;
        }
};

#endif