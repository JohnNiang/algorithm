#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// A1099: Build A Binary Search Tree
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805367987355648>

struct Node {
    int data;
    int lchild;
    int rchild;
} nodes[100];

int keys[100] = {0};
int index = 0;

void inTraversal(int root) {
    if(root == -1) {
        return;
    }
    inTraversal(nodes[root].lchild);

    nodes[root].data = keys[index++];

    inTraversal(nodes[root].rchild);
}

void levelTraversal(int root) {
    queue<int> q;
    q.push(root);
    int i = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(i++ != 0) {
            cout << " ";
        }
        cout << nodes[node].data;
        if(nodes[node].lchild != -1) {
            q.push(nodes[node].lchild);
        }
        if(nodes[node].rchild != -1) {
            q.push(nodes[node].rchild);
        }
    }
}

int main() {
    int N = 0;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int lchild = 0;
        int rchild = 0;
        cin >> lchild >> rchild;
        nodes[i].lchild = lchild;
        nodes[i].rchild = rchild;
    }

    for(int i = 0; i < N; i++) {
        cin >> keys[i];
    }
    // Sort the keys
    sort(keys, keys + N);

    inTraversal(0);

    levelTraversal(0);

    return 0;
}
