#ifndef LORAHA_BINARYTREE_H
#define LORAHA_BINARYTREE_H

#include <iostream>
using namespace std;

#include "Loraha_BinaryTree_Node.h"


template <typename T>
class MyBinaryTreeType{
    private: 
        BSTNode<T>* root = nullptr;
        int count = 0;
        
    public: 
        void insert(T data){
            if (root == nullptr){
                root = new BSTNode<T>(data);
                count++;
            } else {
                BSTNode<T>* current = root;
                while (current){
                    if (data < current->data){ //insert into left
                        if (current->left == nullptr){
                            current->left = new BSTNode<T>(data);
                            current->left->previous = current;
                            count++;
                            return;
                        } else {
                            current = current->left; //so if there already is someone on left, move to left leaf and check again.
                        }
                    } else {
                        if (current->right == nullptr){
                            current->right = new BSTNode<T>(data);
                            current->right->previous = current;
                            count++;
                            return;
                        } else {
                            current = current->right; //so if there already is someone on right, move to right leaf and check again.
                        }
                    }
                }
            }
        }

        string find(T data){
            if (root == nullptr){
                return "False"; //means that the binary tree is empty.
            } else {
                BSTNode<T>* current = root;
                while (current){
                    if (data == current->data){
                        return "True";
                    } else if (data < current->data){ //if true, set current to left one to check again. 
                        current = current->left; 
                    } else if (data > current->data){
                        current = current->right; 
                    }
                }
            } 
            return "False";
        }

        int size(){
            return count;
        }

        int* in_order_traversal(){
            int* array = new int[count];
            int i = 0;
            in_order_traversal_helper(root, array, i);

            return array; 
        }

        void in_order_traversal_helper(BSTNode<T>* check, int* arr, int &j){
           if (root->data){ //checks to see if the tree is empty
                if(check->left){
                    in_order_traversal_helper(check->left, arr, j);
                }
                arr[j] = check->data;
                j++;
                if(check->right){
                    in_order_traversal_helper(check->right, arr, j);
                }
           }
        }

        int* pre_order_traversal(){
            int* array = new int[count];
            int i = 0;
            pre_order_traversal_helper(root, array, i);

            return array;
        }

        void pre_order_traversal_helper(BSTNode<T>* check,  int* arr, int &j){
            if (root->data){
                arr[j] = check->data;
                j++;
                if(check->left){
                    pre_order_traversal_helper(check->left, arr, j);
                }
                if(check->right){
                    pre_order_traversal_helper(check->right, arr, j);
                }
            }
        }

        int* post_order_traversal(){
            int* array = new int[count];
            int i = 0;
            post_order_traversal_helper(root, array, i);

            return array;
        }

        void post_order_traversal_helper(BSTNode<T>* check, int* arr, int &j){
            if (root->data){
                if(check->left){
                    post_order_traversal_helper(check->left, arr, j);
                }
                if(check->right){
                    post_order_traversal_helper(check->right, arr, j);
                }
                arr[j] = check->data;
                j++;
           }
        }

};

#endif
