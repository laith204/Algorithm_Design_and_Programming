#ifndef LORAHA_LINKEDLIST_H
#define LORAHA_LINKEDLIST_H

#include "Loraha_Node.h"

using namespace std;

template <typename T>
class LinkedList{
    public:
        Node<T>* head;
        Node<T>* tail;

        LinkedList(){
            this->head = nullptr;
            this->tail = nullptr;
        }

        void addNodeTop(T data){
            Node<T>* temp = new Node<T>(data);
            if(isEmpty()){
                this->head = temp;
                this->tail = temp;
            } else if(this->head == this->tail){
                this->tail->previous = temp;
                temp->next = this->tail;
                this->head = temp;
            } else {
                this->head->previous = temp;
                temp->next = this->head;
                this->head = temp;
            }
        }

        void addNodeBottom(T data){
            Node<T>* temp = new Node<T>(data);
            if(isEmpty()){
                this->head = temp;
                this->tail = temp;
            } else if(this->head == this->tail){
                this->head->next = temp;
                temp->previous = this->head;
                this->tail = temp;
            } else {
                this->tail->next = temp;
                temp->previous = this->tail;
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
                this->head->previous = nullptr;
            }
            delete node;
        }

        void removeNodeBottom(Node<T>* node){
            if(isEmpty()){
                printf("List is empty\n");
                return;
            } else if (this->head == this->tail){
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                node = this->tail;
                this->tail = this->tail->previous;
                this->tail->next = nullptr;
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
/*
int main(){
    LinkedList* list = new LinkedList();
    list->addNodeTop(1);
    list->addNodeTop(2);
    list->addNodeTop(3);
    list->addNodeBottom(4);
    list->addNodeBottom(5);
    list->addNodeBottom(6);
    list->printList();
    //list->removeNodeTop(list->getHead());
    list->printList();
   // list->removeNodeBottom(list->getTail());
    list->printList();

    cout << "Here: " << list->getData(list->getHead()->next) << endl;
    cout << "Here: " << list->getData(list->getTail()) << " " << list->getData(list->getTail()->previous) << endl;
    return 0;
}
*/