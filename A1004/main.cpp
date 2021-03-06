#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// A1004: Counting Leaves
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184>

vector<int> genealogy[100];
int counts[100] = {0};
int maxDeepth = -1;

void dfs(int root, int deepth) {
    if(genealogy[root].empty()) {
        counts[deepth]++;
        if(deepth > maxDeepth) {
            maxDeepth = deepth;
        }
        return;
    }

    for(int i = 0; i < genealogy[root].size(); i++) {
        dfs(genealogy[root].at(i), deepth + 1);
    }
}

/**
 * Another sulution.
 */
int nodeDeepth[100] = {0};

void bfs() {
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int i = q.front();
        q.pop();
        maxDeepth = max(maxDeepth, nodeDeepth[i]);
        if(genealogy[i].empty()) {
            // Leaf node
            counts[nodeDeepth[i]]++;
        }
        for(int k = 0; k < genealogy[i].size(); k++) {
            nodeDeepth[genealogy[i].at(k)] = nodeDeepth[i] + 1;
            q.push(genealogy[i].at(k));
        }
    }
}

int main() {
    int M = 0;
    int N = 0;
    cin >> M >> N;

    for(int i = 0; i < N; i++) {
        int nonLeaf = 0;
        int c = 0;
        cin >> nonLeaf >> c;
        while(c--) {
            int child = 0;
            cin >> child;
            genealogy[nonLeaf].push_back(child);
        }
    }

    dfs(1, 0);
    //    bfs();
    for(int i = 0; i <= maxDeepth; i++) {
        if(i != 0) {
            cout << " ";
        }
        cout << counts[i];
    }
    return 0;
}
