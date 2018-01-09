/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.h
 * Author: Karus Labs
 *
 * Created on January 9, 2018, 11:55 AM
 */

#ifndef TREE_H
#define TREE_H

#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;


namespace Practical {
    
    template <class T>
    struct Node {
        
        T value;
        Node<T>* left;
        Node<T>* right;
        
        
        Node(T value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
        
    };
    
    
    template <class T>
    class BinarySearchTree {
        private:
            Node<T>* root;
            
        public:
            BinarySearchTree();

            Node<T>* search(T target);
            Node<T>* search(Node<T>* root, T target);

            void insert(T value);
            void insert(Node<T>* &root, T value);

            void remove(T target);
            void remove(Node<T>* &root, T target);

            void inorder();
            void inorder(Node<T>* t);

            void preorder();
            void preorder(Node<T>* t);

            void postorder();
            void postorder(Node<T>* t);

            int getHeight(Node<T>* t = root);

            int countNodes(Node<T>* t = root);

            bool isEmoty();

            bool isBalanced(Node<T> *t = root);
            
    };
    
    
    template <class T>
    BinarySearchTree::BinarySearchTree() {
        root = nullptr;
    }

    
    template <class T>
    Node<T>* BinarySearchTree::search(T target) {
        return search(root, target);
    }

    template <class T>
    Node<T>* BinarySearchTree::search(Node<T>* t, T target) {
        if (t == nullptr) // value not found
            return nullptr;
        else {
            if (t->value == target) // value found
                return t;
            else
                if (target < t->value) // search in left subtree
                return search(t->left, target);
            else // search in right subtree
                return search(t->right, target);
        }
    }

    
    template <class T>
    void BinarySearchTree::insert(T value) {
        insert(root, value);
    }
    
    template <class T>
    void BinarySearchTree::insert(Node<T>* &t, T value) {
        if (t == nullptr) {
            Node<T> *newNode = new Node<T>;
            newNode->value = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            t = newNode;
        } else
            if (value < t->value)
            insert(t->left, value); // insert in left subtree
        else
            insert(t->right, value); // insert in right subtree
    }

    
    template <class T>
    void BinarySearchTree::inorder() {
        if (isEmoty())
            cout << "No value found" << endl;
        else
            inorder(root);
    }
    
    template <class T>
    void BinarySearchTree::inorder(Node<T>* t) {
        if (t != nullptr) {
            inorder(t->left);
            cout << t->value << endl;
            inorder(t->right);

        }
    }
    
    
    template <class T>
    void BinarySearchTree::preorder() {
        if (isEmoty())
            cout << "No value found" << endl;
        else
            preorder(root);
    }

    template <class T>
    void BinarySearchTree::preorder(Node<T>* t) {
        if (t != nullptr) {
            cout << t->value << endl;
            preorder(t->left);
            preorder(t->right);
        }
    }

   
    template <class T>
    void BinarySearchTree::postorder() {
        if (isEmoty())
            cout << "No value found" << endl;
        else
            postorder(root);
    }
    
    template <class T>
    void BinarySearchTree::postorder(Node<T>* t) {
        if (t != nullptr) {
            postorder(t->left);
            postorder(t->right);
            cout << t->value << endl;
        }
    }

    
    template <class T>
    int BinarySearchTree::getHeight() {
        return getHeight(root);
    }
    
    template <class T>
    int BinarySearchTree::getHeight(Node<T>* t) {
        if (t == nullptr)
            return 0;
        else {
            // return 1 + max(getHeight(t->left), getHeight(t->right));
            int leftHeight = getHeight(t->left);
            int rightHeight = getHeight(t->right);
            if (leftHeight > rightHeight)
                return leftHeight + 1;
            else
                return rightHeight + 1;
        }
    }

    
    template <class T>
    int BinarySearchTree::countNodes() {
        return countNodes(root);
    }
    
    template <class T>
    int BinarySearchTree::countNodes(Node<T>* t) {
        if (t == nullptr)
            return 0;
        else
            return 1 + countNodes(t->left) + countNodes(t->right);
    }

    
    template <class T>
    bool BinarySearchTree::isBalanced() {
        return isBalanced(root);
    }
    
    template <class T>
    bool BinarySearchTree::isBalanced(Node<T> *t) {
        if (t != nullptr) {
            int leftHeight = getHeight(t->left); // height of left sub-tree
            int rightHeight = getHeight(t->right); // height of right sub-tree
            bool isBalancedNode = (abs(leftHeight - rightHeight) <= 1);
            return (isBalancedNode && isBalanced(t->left) && isBalanced(t->right));
        } else
            return true;
    }

    
    template <class T>
    bool BinarySearchTree::isEmoty() {
        return (root == nullptr);
    }

    
    template <class T>
    void BinarySearchTree::remove(T target) {
        remove(root, target);
    }
    
    template <class T>
    void BinarySearchTree::remove(Node<T>* &t, T target) {
        // search for the node to be deleted
        Node<T>* current = t;
        Node<T>* parent = nullptr;
        bool isLeftChild = false;
        bool found = false;
        while ((!found) && (current != nullptr)) {
            if (target == current->value) {
                found = true;
            } else {
                parent = current;
                if (target < current->value) {
                    current = current->left; // go to left subtree
                    isLeftChild = true;
                } else {
                    current = current->right; // go to right subtree
                    isLeftChild = false;
                }
            }
        }

        if (found) {
            // -----------------------  case 1 : node is a leaf ------------------------
            if (current->left == nullptr && current->right == nullptr) {
                if (current == t) // node to be deleted is a root
                    t = nullptr;
                else
                    if (isLeftChild)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            } else
                // -----------------------  case 2 : node has only 1 child  ----------------
                if (current->left == nullptr) {
                if (isLeftChild)
                    parent->left = current->right;
                else
                    parent->right = current->right;
                ;
            } else
                if (current->right == nullptr) {
                if (isLeftChild)
                    parent->left = current->left;
                else
                    parent->right = current->left;
                ;
            } else
                // -----------------------  case 3 : node has 2 children  ------------------
            {
                // find the successor ( rightmost child in the node’s left subtree)
                Node<T>* successor = current->left;
                while (successor->right != nullptr)
                    successor = successor->right;
                // replace the node’s value with that of the successor
                int n = successor->value;
                // delete the successor (either case 1 or case 2)
                remove(t, n);
                // replace the node’s value with that of the successor
                current->value = n;
            }
        }
    }
    
    
    template <class T>
    int BinarySearchTree::getHeight(Node<T>* node = root) {
        if (node) {
            return 1 + max(getHeight(node->left), getHeight(root->right));
            
        } else {
            return 0;
        }
    }
    
    
    template <class T>
    int BinarySearchTree::countNodes(Node<T>* node = root) {
        if (node) {
            return 1 + countNodes(node->left) + countNodes(node->right);
            
        } else {
            return 0;
        }
    }
    
    
    template <class T>
    bool BinarySearchTree::isBalanced(Node<T>* node = root) {
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        
        return abs(left - right) <= 1 && isBalanced(node->left) && isBalanced(node->right);
    }
    
}
#endif /* TREE_H */

