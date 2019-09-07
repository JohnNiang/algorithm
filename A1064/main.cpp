#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A1064: Complete Binary Search Tree
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805407749357568>

vector<int> raw;
vector<int> cbt;

int N = 0;
int index = 0;

void inTraversal(int root) {
    if(root >= N) {
        return;
    }
    // Left child
    inTraversal(root * 2 + 1);

    // root
    cbt[root] = raw[index++];

    // Right child
    inTraversal(root * 2 + 2);
}


int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int key = 0;
        cin >> key;
        raw.push_back(key);
    }

    sort(raw.begin(), raw.end());

    cbt.resize(N);

    inTraversal(0);

    for(int i = 0; i < N; i++) {
        if(i != 0) {
            cout << " ";
        }
        cout << cbt[i];
    }
    return 0;
}
