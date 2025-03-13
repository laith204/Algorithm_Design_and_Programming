#ifndef LORAHA_BINARYTREE_NODE_H
#define LORAHA_BINARYTREE_NODE_H

template <typename T>
class BSTNode{
    public:
        T data;
        BSTNode<T>* left;
        BSTNode<T>* right;
        BSTNode<T>* previous;

        BSTNode(T data){
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
            this->previous = nullptr;
        }

        T getData(){
            return this->data;
        }

};

#endif