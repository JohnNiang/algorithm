#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// A1106: Lowest Price in Supply Chain
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805362341822464>

vector<int> nodes[1000000];
int lowestDeepth = 1000000;
int lowestCount = 0;

int N = 0;
double P = 0;
double r = 0;

void dfs(int root,int deepth) {
    if(nodes[root].empty()) {
        // Child node
        if(deepth < lowestDeepth) {
            lowestDeepth = deepth;
            lowestCount = 1;
        } else if(deepth == lowestDeepth) {
            lowestCount++;
        }
    }
    for(int i = 0; i < nodes[root].size(); i++) {
        dfs(nodes[root].at(i), deepth + 1);
    }
}

int main() {
    cin >> N >> P >> r;
    r /= 100;
    for(int i = 0; i < N; i++) {
        int count = 0;
        cin >> count;
        while(count--) {
            int child = 0;
            cin >> child;
            nodes[i].push_back(child);
        }
    }
    dfs(0, 0);
    printf("%.4f %d", P * pow(1 + r, lowestDeepth), lowestCount);
    return 0;
}
