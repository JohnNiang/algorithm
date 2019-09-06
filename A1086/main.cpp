#include <iostream>
#include <stack>

using namespace std;

// A1086: Tree Traversals Again
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805380754817024>

struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};

int pre[30];
int in[30];
int N = 0;
int total = 0;

Node* createByPreAndIn(int preL, int preR, int inL, int inR) {
    if(preL > preR) {
        return nullptr;
    }

    Node* root = new Node;
    root->data = pre[preL];

    // Find root in in-order
    int m = inL;
    for(; m <= inR; m++) {
        if(in[m] == pre[preL]) {
            break;
        }
    }

    int lefts = m - inL;

    root->lchild = createByPreAndIn(preL + 1, preL + lefts, inL, m - 1);
    root->rchild = createByPreAndIn(preL + lefts + 1, preR, m + 1, inR);

    return root;
}

void postTraversal(Node* root) {
    if(root == nullptr) {
        return;
    }

    postTraversal(root->lchild);
    postTraversal(root->rchild);

    if(total != 0) {
        cout << " ";
    }
    total++;
    cout << root->data;
}

int main() {
    cin >> N;

    stack<int> s;
    int preIndex = 0;
    int inIndex = 0;
    for(int i = 0; i < 2 * N; i++) {
        string operate;
        cin >> operate;
        if(operate == "Push") {
            int nodeIndex = 0;
            cin >> nodeIndex;
            s.push(nodeIndex);
            pre[preIndex++] = nodeIndex;
        } else {
            int nodeIndex = s.top();
            s.pop();
            in[inIndex++] = nodeIndex;
        }
    }

    // Create the tree
    Node* root = createByPreAndIn(0, N - 1, 0, N - 1);

    postTraversal(root);

    return 0;
}
