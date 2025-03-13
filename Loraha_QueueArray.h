#ifndef LORAHA_QUEUEARRAY_H
#define LORAHA_QUEUEARRAY_H

#include <iostream>

using namespace std;

template <typename T>
class MyQueueArrayType{
    private:
        T* stack = new T[1];
        int stackSize = 1; //size of stack after adding an element... starts at 1, but that 1 is to know if its empty.

    public:
        MyQueueArrayType(){
            stack[0] = -1; //initialize stack with -1, if top is -1, then stack is empty.
        }

        void print(){
            for (int i = 0; i < stackSize; i++){
                cout << stack[i] << " ";
            }
            cout << endl;
        }

        int size(){
            return stackSize - 1; //return size of stack, but -1 because of the -1 that is used to check if stack is empty.
        }

        void enqueue(T data){
            T* temp = new T[stackSize + 1];
            for (int i = 0; i < stackSize; i++){
                temp[i] = stack[i];
            }
            temp[stackSize] = data;
            delete[] stack;
            stack = temp;
            stackSize++;
        }  

        string is_empty(){
            if (stackSize == 1){
                return "True";
            } else {
                return "False";
            }
        }

        T deque(){
            if (stackSize != 1){
                T* temp = new T[stackSize - 1];
                for (int i = 0; i < stackSize - 1; i++){
                    temp[i] = stack[i + 1];
                }
                T data = stack[1];
                delete[] stack;
                stack = temp;
                stackSize--;
                return data;
            } else {
                return -1; //stack is empty if -1 is returned. have the if statement here to not remove the -1 that is used to check if stack is empty.
            }
        }

        T front(){
            if (stackSize != 1){
                return stack[1];
            } else {
                return -1; //stack is empty if -1 is returned. have the if statement here to not remove the -1 that is used to check if stack is empty.
            }
        }

};

#endif