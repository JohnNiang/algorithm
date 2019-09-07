#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A1053: Path of Equal Weight
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805424153280512>

struct Node {
    int weight;
    vector<int> next;
} nodes[100];

int S = 0;

int paths[100] = {0};

void dfs(int root, int weightSum, int path) {
    paths[path] = nodes[root].weight;
    if(nodes[root].next.empty()) {
        // If the node is leaf node
        if(nodes[root].weight + weightSum == S) {
            // Print this path
            for(int i = 0; i <= path; i++) {
                if(i != 0) {
                    cout << " ";
                }
                cout << paths[i];
            }
            cout << endl;
        }
    }

    for(int i = 0; i < nodes[root].next.size(); i++) {
        dfs(nodes[root].next.at(i), nodes[root].weight + weightSum, path + 1);
    }
}

bool weightCmp(int left, int right) {
    return nodes[left].weight > nodes[right].weight;
}

int main() {
    int N = 0;
    int M = 0;

    cin >> N >> M >> S;

    for(int i = 0; i < N; i++) {
        cin >> nodes[i].weight;
    }

    for(int i = 0; i < M; i++) {
        int node = 0;
        int m = 0;
        cin >> node >> m;
        while(m--) {
            int child = 0;
            cin >> child;
            nodes[node].next.push_back(child);
            sort(nodes[node].next.begin(), nodes[node].next.end(), weightCmp);
        }
    }

    dfs(0, 0, 0);

    return 0;
}
