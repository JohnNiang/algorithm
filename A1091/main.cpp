#include <iostream>
#include <queue>

using namespace std;

// A1091: Acute Stroke
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805375457411072>

int m, n, l, t;

bool nodes[1287][129][61];
bool visits[1287][129][61];

int X[] = {0, 0, -1, 1, 0, 0};
int Y[] = {0, 0, 0, 0, 1, -1};
int Z[] = {1, -1, 0, 0, 0, 0};

struct Node {
    int x;
    int y;
    int z;
} node;

bool judge(int x, int y, int z) {
    if(x < 0 || y < 0 || z < 0 || x >= m || y >= n || z >= l) {
        return false;
    }

    if(!nodes[x][y][z] || visits[x][y][z]) {
        return false;
    }

    return true;
}

int bfs(int x, int y, int z) {
    node.x = x;
    node.y = y;
    node.z = z;

    int total = 0;

    queue<Node> q;
    q.push(node);
    visits[x][y][z] = true;
    while(!q.empty()) {
        Node n = q.front();
        q.pop();
        total++;
        for(int i = 0; i < 6; i++) {
            int newX = n.x + X[i];
            int newY = n.y + Y[i];
            int newZ = n.z + Z[i];

            if(judge(newX, newY, newZ)) {
                visits[newX][newY][newZ] = true;
                node.x = newX;
                node.y = newY;
                node.z = newZ;
                q.push(node);
            }
        }
    }

    return total >= t ? total : 0;
}

int main() {
    cin >> m >> n >> l >> t;
    for(int z = 0; z < l; z++) {
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                cin >> nodes[x][y][z] ;
            }
        }
    }

    int answer = 0;
    for(int x = 0; x < m; x++) {
        for(int y = 0; y < n; y++) {
            for(int z = 0; z < l; z++) {
                if(!visits[x][y][z] && nodes[x][y][z]) {
                    answer += bfs(x, y, z);
                }
            }
        }
    }

    cout << answer << endl;
    return 0;
}
