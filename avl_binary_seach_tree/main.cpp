#include <iostream>

using namespace std;

// AVL binary search tree

struct Node {
    int data;
    int height;
    Node* lchild;
    Node* rchild;
};

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->lchild = node->rchild = nullptr;
    node->height = 1;
    return node;
}

int getHeight(Node* root) {
    if(!root) {
        return 0;
    }
    root->height;
}

int getBalanceFactor(Node* root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(Node* root) {
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void LeftRotate(Node* &root) {
    Node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    // The order could not reverse
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void rightRotate(Node* &root) {
    Node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(Node* &root, int data) {
    if(root == nullptr) {
        root = newNode(data);
        return;
    }

    if(data < root->data) {
        insert(root->lchild, data);
        updateHeight(root);
        if(getBalanceFactor(root) == 2) {
            // L
            if(getBalanceFactor(root->lchild) == 1) {
                // LL
                rightRotate(root);
            } else if(getBalanceFactor(root->lchild) == -1) {
                // LR
                LeftRotate(root->lchild);
                rightRotate(root);
            }
        }
    } else {
        insert(root->rchild, data);
        updateHeight(root);
        if(getBalanceFactor(root) == -2) {
            // R
            if(getBalanceFactor(root->rchild) == -1) {
                // RR
                LeftRotate(root);
            } else if(getBalanceFactor(root->rchild) == 1) {
                // RL
                rightRotate(root->rchild);
                LeftRotate(root);
            }
        }
    }
}

int main() {
    return 0;
}
