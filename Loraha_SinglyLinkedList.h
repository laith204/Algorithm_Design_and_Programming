#ifndef LORAHA_SINGLYLINKEDLIST_H
#define LORAHA_SINGLYLINKEDLIST_H

#include "Loraha_Node.h"

using namespace std;

template <typename T>
class SinglyLinkedList{
    public:
        Node<T>* head;
        Node<T>* tail;

        SinglyLinkedList(){
            this->head = nullptr;
            this->tail = nullptr;
        }

        void addNodeBottom(T data){
            Node<T>* temp = new Node<T>(data);
            if(isEmpty()){
                this->head = temp;
                this->tail = temp;
            } else if(this->head == this->tail){
                this->head->next = temp;
                this->tail = temp;
            } else {
                this->tail->next = temp;
                this->tail = temp;
            }
        }

        void removeNodeTop(Node<T>* node){
            if(isEmpty()){
                std::cout << "List is empty\n";
                return;
            } else if (this->head == this->tail){
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                node = this->head;
                this->head = this->head->next;
            }
            delete node;
        }

        bool isEmpty(){
            return (this->head == nullptr);
        }

        void printList(){
            Node<T>* temp = this->head;
            while(temp != nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
            printf("\n");
        }
            

        T getData(Node<T>* node){
                return node->data;
        }

        Node<T>* getHead(){
            return this->head;
        }

        Node<T>* getTail(){
            return this->tail;
        }

};

#endif