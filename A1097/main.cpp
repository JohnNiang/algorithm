#include <iostream>

using namespace std;

// A1097: Deduplication on a Linked List
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805369774129152>

// Nodes: 这里需要注意的是，dataMap 的长度必须大于 10000。
struct Node {
    int addr;
    int data;
    int next;
    bool first;
} nodes[100000];

bool dataMap[10001] = {false};

void printWithNext(int current, int next) {
    printf("%05d %d", nodes[current].addr, nodes[current].data);
    if(next == -1) {
        printf(" -1\n");
    } else {
        printf(" %05d\n",nodes[next].addr);
    }
}

int main() {
    int head = 0;
    int N = 0;
    cin >> head >> N;

    for(int i = 0; i < N; i++) {
        int addr = 0;
        cin >> addr;
        cin >> nodes[addr].data >> nodes[addr].next;
        nodes[addr].addr = addr;
    }

    // Find the first
    int current = head;
    while(current != -1) {
        int absData = abs(nodes[current].data);
        if(!dataMap[absData]) {
            nodes[current].first = true;
        }
        dataMap[absData] = true;
        current = nodes[current].next;
    }

    // Handle the result list
    current = head;
    while(current != -1) {
        int next = nodes[current].next;
        while(next != -1 && !nodes[next].first) {
            next = nodes[next].next;
        }
        printWithNext(current, next);
        current = next;
    }

    // Handle the removed list
    current = head;
    while(current != -1 && nodes[current].first) {
        current = nodes[current].next;
    }
    while(current != -1) {
        int next = nodes[current].next;
        while(next != -1 && nodes[next].first) {
            next = nodes[next].next;
        }
        printWithNext(current, next);
        current = next;
    }

    return 0;
}
