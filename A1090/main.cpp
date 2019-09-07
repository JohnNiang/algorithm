#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// A1090: Highest Price in Supply Chain
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805376476626944>

struct Node {
    vector<int> next;
} nodes[100000];

int N = 0;
double P = 0.0;
double r = 0.0;

int maxDeep = -1;
int maxTotal = 0;

void traversal(int root, int deep) {
    if(deep == maxDeep) {
        maxTotal++;
    }

    if(deep > maxDeep) {
        maxDeep = deep;
        maxTotal = 1;
    }

    if(nodes[root].next.empty()) {
        return;
    }

    for(int i = 0; i < nodes[root].next.size(); i++) {
        traversal(nodes[root].next.at(i), deep + 1);
    }
}

int main() {
    cin >> N >> P >> r;
    r /= 100;

    int root = 0;
    for(int i = 0; i < N; i++) {
        int supplier = 0;
        cin >> supplier;
        if(supplier != -1) {
            nodes[supplier].next.push_back(i);
        } else {
            root = i;
        }
    }

    traversal(root, 0);

    double highestPrice = P * pow(1 + r, maxDeep);
    printf("%.2f %d", highestPrice, maxTotal);

    return 0;
}
