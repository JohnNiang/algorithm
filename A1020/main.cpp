#include <iostream>
#include <queue>

using namespace std;

// A1020: Tree Traversals
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805485033603072>

struct Node {
    int data;
    Node* left;
    Node* right;
};

int post[30];
int in[30];

Node* create(int postL, int postR, int inL, int inR) {
    if(postL > postR) {
        return nullptr;
    }

    Node* root = new Node;
    root->data = post[postR];

    // Find root in in-order
    int m = inL;
    for(; m <= inR; m++) {
        if(in[m] == post[postR]) {
            break;
        }
    }

    int lefts = m - inL;

    root->left = create(postL, postL + lefts - 1, inL, m - 1);
    root->right = create(postL + lefts, postR - 1, m + 1, inR);

    return root;
}

void levelTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    int total = 0;
    while(!q.empty()) {
        Node* node =  q.front();
        q.pop();
        if(total != 0) {
            cout << " ";
        }
        total++;
        cout << node->data;
        if(node->left != nullptr) {
            q.push(node->left);
        }
        if(node->right != nullptr) {
            q.push(node->right);
        }
    }
}

int main() {
    int N = 0;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> post[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> in[i];
    }

    Node* root = create(0, N - 1, 0, N - 1);
    levelTraversal(root);
    return 0;
}
