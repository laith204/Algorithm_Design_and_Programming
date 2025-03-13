#ifndef LORAHA_QUEUELINKEDLIST_H
#define LORAHA_QUEUELINKEDLIST_H

#include <iostream>
#include "Loraha_SinglyLinkedList.h"

using namespace std;


template <typename T>
class MyQueueLinkedListType {
    private:
    SinglyLinkedList<T> stack;
    public:
        void enqueue(T data){
            stack.addNodeBottom(data);
        }

        T deque(){
            if(stack.isEmpty()){
                cout << "Stack is empty: ";
                return 0;
            } else{
                T data = stack.getData(stack.getHead());
                stack.removeNodeTop(stack.getHead());
                
                return data;
            }
        }

        T front(){
            return stack.getData(stack.getHead());
        }

        string is_empty(){
            if(stack.isEmpty()){
                return "True";
            } else {
                return "False";
            };
        }

        int size(){
            int count = 0;
            Node<T>* temp = stack.getHead();
            while(temp != nullptr){
                count++;
                temp = temp->next;
            }
            return count;
        }
};

#endif

/*
int main(){
    MyQueueLinkedListType<int>* stack = new MyQueueLinkedListType<int>();

    stack->enqueue(1);
    cout << stack->front() << endl;
    stack->enqueue(2);
    cout << stack->front() << endl;
    stack->enqueue(3);
    cout << stack->front() << endl;
    cout << stack->is_empty() << endl;
    cout << "SIZE: " << stack->size() << endl;
    cout << "Deque: " << stack->deque() << endl;
    cout << stack->front() << endl;
    cout << "SIZE: " << stack->size() << endl;
    cout << "Deque: " << stack->deque() << endl;
    cout << "Deque: " << stack->deque() << endl;
    cout << "Deque: " << stack->deque() << endl;
    cout << stack->is_empty() << endl;
    cout << "Deque: " << stack->deque() << endl;
    cout << stack->is_empty() << endl;
    cout << "SIZE: " << stack->size() << endl;
    cout << "Deque: " << stack->deque() << endl;
    cout << stack->is_empty() << endl;
    cout << "SIZE: " << stack->size() << endl;
    stack->enqueue(1);
    cout << stack->front() << endl;
    cout << stack->is_empty() << endl;
    cout << "SIZE: " << stack->size() << endl;


    cout << "THIS WAS QUEUE LINKED LIST" << endl;
    return 0;
}
    */