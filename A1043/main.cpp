#include <iostream>
#include <vector>

using namespace std;

// A1043: Is It a Binary Search Tree
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805440976633856>

struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};

int N = 0;
vector<int> raw;
vector<int> pre;
vector<int> post;
vector<int> preMirror;
vector<int> postMirror;

void insert(Node* &root, int data) {
    if(root == nullptr) {
        root = new Node;
        root->data = data;
        root->lchild = root->rchild = nullptr;
        return;
    }

    if(data >= root->data) {
        insert(root->rchild, data);
    } else {
        insert(root->lchild, data);
    }
}


void preTraversal(Node* root, bool mirror) {
    if(root == nullptr) {
        return;
    }
    if(mirror) {
        preMirror.push_back(root->data);
    } else {
        pre.push_back(root->data);
    }
    preTraversal(mirror ? root->rchild : root->lchild, mirror);
    preTraversal(mirror ? root->lchild : root->rchild, mirror);
}

void postTraversal(Node* root, bool mirror) {
    if(root == nullptr) {
        return;
    }
    postTraversal(mirror ? root->rchild : root->lchild, mirror);
    postTraversal(mirror ? root->lchild : root->rchild, mirror);
    if(mirror) {
        postMirror.push_back(root->data);
    } else {
        post.push_back(root->data);
    }
}

int main() {
    cin >> N;
    Node* bst = nullptr;
    for(int i = 0; i < N; i++) {
        int data = 0;
        cin >> data;
        raw.push_back(data);
        insert(bst, data);
    }

    preTraversal(bst, false);
    // Mirror
    preTraversal(bst, true);

    postTraversal(bst, false);
    // Mirror
    postTraversal(bst, true);

    if(raw == pre) {
        cout << "YES" << endl;
        for(int i = 0; i < post.size(); i++) {
            if(i != 0) {
                cout << " ";
            }
            cout << post.at(i);
        }
    } else if(raw == preMirror) {
        cout << "YES" << endl;
        for(int i = 0; i < postMirror.size(); i++) {
            if(i != 0) {
                cout << " ";
            }
            cout << postMirror.at(i);
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
