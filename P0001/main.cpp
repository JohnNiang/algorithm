#include <iostream>
#include <queue>

using namespace std;

// P0001: 求解n*m矩阵中的分块儿个数

const int MAX = 100;

int X[] = {0, 0, -1, 1};
int Y[] = {1, -1, 0, 0};

int totalBlock = 0;
int n = 0;
int m = 0;

bool visits[MAX][MAX] = {false};
bool nodes[MAX][MAX] = {false};

struct Node {
    int x;
    int y;
} node;

bool check(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m) {
        return false;
    }

    if(visits[x][y] || !nodes[x][y]) {
        return false;
    }

    return true;
}

void bfs(int x, int y) {
    queue<Node> q;
    node.x = x;
    node.y = y;
    q.push(node);
    while(!q.empty()) {
        // Get front
        Node n = q.front();
        visits[n.x][n.y] = true;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int x = n.x + X[i];
            int y = n.y + Y[i];

            if(check(x, y)) {
                node.x = x;
                node.y = y;
                q.push(node);
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> nodes[i][j];
        }
    }

    int answer = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(nodes[i][j] && !visits[i][j]) {
                answer++;
                bfs(i, j);
                cout << "i = " << i << ", j = " << j << endl;
            }
        }
    }

    printf("%d", answer);
    return 0;
}
