#include <iostream>

using namespace std;

// Delete binary tree

struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};

Node* findMax(Node* root) {
    while(root->rchild) {
        root = root->rchild;
    }
    return root;
}

Node* findMin(Node* root) {
    while(root->lchild) {
        root = root->lchild;
    }
    return root;
}

void deleteNode(Node* &root, int x) {
    if(root == nullptr) {
        return;
    }

    if(x > root->data) {
        deleteNode(root->rchild, x);
    } else if(x < root->data) {
        deleteNode(root->lchild, x);
    } else {
        if(!root->lchild && !root->rchild) {
            delete root;
            root = nullptr;
            return;
        } else if(root->lchild) {
            // Find pre node
            Node* pre = findMax(root);
            // Cover data
            root->data = pre->data;
            // Delete pre-node from left child
            deleteNode(root->lchild, pre->data);
        } else if(root->rchild) {
            // Find next node
            Node* next = findMin(root);
            // Cover data
            root->data = next->data;
            // Delete next-node from right child
            deleteNode(root->rchild, next->data);
        }
    }
}

int main() {
    return 0;
}
