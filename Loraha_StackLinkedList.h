#ifndef LORAHA_STACKLINKEDLIST_H
#define LORAHA_STACKLINKEDLIST_H

#include <iostream>
#include "Loraha_LinkedList.h"

using namespace std;


template <typename T>
class MyStackLinkedListType {
    private:
    LinkedList<T> stack;
    public:
        void push(T data){
            stack.addNodeTop(data);
        }

        T pop(){
            if(stack.isEmpty()){
                cout << "Stack is empty: ";
                return 0;
            } else{
                T data = stack.getData(stack.getHead());
                stack.removeNodeTop(stack.getHead());
                
                return data;
            }
        }

        T top(){
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
    MyStackLinkedListType<int>* stack = new MyStackLinkedListType<int>();

    stack->push(1);
    cout << stack->top() << endl;
    stack->push(2);
    cout << stack->top() << endl;
    stack->push(3);
    cout << "SIZE: " << stack->size() << endl;
    cout << stack->pop() << endl;
    cout << stack->top() << endl;
    cout << "SIZE: " << stack->size() << endl;
    cout << stack->pop() << endl;

    cout << stack->is_empty() << endl;

    cout << stack->pop() << endl;
    cout << stack->pop() << endl;
    cout << stack->pop() << endl;
    cout << stack->size() << endl;



    cout << "THIS WAS LINKED LIST STACK" << endl;
    return 0;
}
    */