#include <iostream>

using namespace std;

// A1032: Sharing
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805460652113920>

struct Node {
    char data;
    bool flag;
    int address;
    int next;
} nodes[100000];

int main() {
    int first = 0;
    int second = 0;
    int N = 0;
    cin >> first >> second >> N;

    for(int i = 0; i < N; i++) {
        int address = 0;
        cin >> address;
        cin >> nodes[address].data >> nodes[address].next;
        nodes[address].address = address;
    }

    int head = first;
    while(head != -1) {
        nodes[head].flag = true;
        head = nodes[head].next;
    }

    head = second;
    bool hasCommon = false;
    while(head != -1) {
        if(nodes[head].flag) {
            hasCommon = true;
            break;
        }
        head = nodes[head].next;
    }

    if(hasCommon) {
        printf("%05d\n", head);
    } else {
        cout << "-1" << endl;
    }

    return 0;
}
