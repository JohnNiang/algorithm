#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// A1079: Total Sales of Supply Chain
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805388447170560>

struct Node {
    int amount;
    vector<int> next;
} nodes[100000];

int N = 0;
double P = 0.0;
double r = 0.0;
double total = 0.0;

void  calculate(int root, int deep) {
    if(root < 0 || root >= N) {
        return;
    }

    if(nodes[root].next.size() == 0) {
        // If the node is leaf, then get the amount
        int amount = nodes[root].amount;
        total += amount * pow(1 + r, deep);
    } else {
        for(int i = 0; i < nodes[root].next.size(); i++) {
            calculate(nodes[root].next.at(i), deep + 1);
        }
    }
}

int main() {
    cin >> N >> P >> r;

    r /= 100;

    for(int i = 0; i < N; i++) {
        // Input the Ki
        int k = 0;
        cin >> k;
        if(k == 0) {
            cin >> nodes[i].amount;
            continue;
        }

        for(int j = 0; j < k; j++) {
            int next = 0;
            cin >> next;
            nodes[i].next.push_back(next);
        }
    }

    calculate(0, 0);

    printf("%.1f", total * P);
    return 0;
}
