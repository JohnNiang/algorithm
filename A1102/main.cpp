#include <iostream>
#include <queue>

using namespace std;

// A1102: Invert a Binary Tree
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805365537882112>

int N = 0;
int total = 0;

struct Node {
    int data;
    int lchild;
    int rchild;
} nodes[10];

void reverse(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int i = q.front();
        q.pop();
        if(nodes[i].lchild != -1) {
            q.push(nodes[i].lchild);
        }
        if(nodes[i].rchild != -1) {
            q.push(nodes[i].rchild);
        }

        // Switch the lchild and rchild
        int temp = nodes[i].lchild;
        nodes[i].lchild = nodes[i].rchild;
        nodes[i].rchild = temp;
    }
}

void levelTraversal(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int i = q.front();
        q.pop();
        if(total++ != 0) {
            cout << " ";
        }
        cout << nodes[i].data;
        if(nodes[i].lchild != -1) {
            q.push(nodes[i].lchild);
        }
        if(nodes[i].rchild != -1) {
            q.push(nodes[i].rchild);
        }
    }
}

void inTraversal(int root) {
    if(root == -1) {
        return;
    }

    inTraversal(nodes[root].lchild);

    // Visit it
    if(total++ != 0) {
        cout << " ";
    }
    cout << nodes[root].data;

    inTraversal(nodes[root].rchild);
}

int main() {
    cin >> N;
    bool children[10] = {false};
    for(int i = 0; i < N; i++) {
        nodes[i].data = i;
        string child;

        // Handle lchild
        cin >> child;
        if(child == "-") {
            nodes[i].lchild = -1;
        } else {
            nodes[i].lchild = stoi(child);
            children[nodes[i].lchild] = true;
        }
        cin >> child;
        if(child == "-") {
            nodes[i].rchild = -1;
        } else {
            nodes[i].rchild = stoi(child);
            children[nodes[i].rchild] = true;
        }
    }

    // Find the root node
    int i = 0;
    for(; i < N; ) {
        if(!children[i]) {
            break;
        }
        i++;
    }

    reverse(i);
    total = 0;
    levelTraversal(i);
    total = 0;
    cout << endl;
    inTraversal(i);
    return 0;
}
