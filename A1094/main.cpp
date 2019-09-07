#include <iostream>
#include <vector>

using namespace std;

// A1094: The Largest Generation
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805376476626944>

const int MAX = 100;
vector<int> genealogy[101];
int deepthCount[101] = {0};
int maxDeepth = 0;
int N = 0;
int M = 0;

void traversal(int root, int deepth) {
    if(deepth > maxDeepth) {
        maxDeepth = deepth;
    }
    deepthCount[deepth]++;
    if(genealogy[root].empty()) {
        return;
    }
    for(int i = 0; i < genealogy[root].size(); i++) {
        traversal(genealogy[root].at(i), deepth + 1);
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int father = 0;
        int count = 0;
        cin >> father >> count;
        while(count--) {
            int child = 0;
            cin >> child;
            genealogy[father].push_back(child);
        }
    }

    traversal(1, 1);

    int d = 0;
    int maxGeneration = 0;
    for(int i = 1; i <= maxDeepth; i++) {
        if(deepthCount[i] > maxGeneration) {
            d = i;
            maxGeneration = deepthCount[i];
        }
    }

    cout << maxGeneration << " " << d << endl;
    return 0;
}
