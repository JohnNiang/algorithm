#include <iostream>
#include <algorithm>

using namespace std;

// A1052: Linked List Sorting
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805425780670464>

struct Node {
    int address;
    int data;
    int next;
} lists[100000], valids[100000];

bool dataCompare(Node& left, Node& right) {
    return left.data < right.data;
}

int main() {
    int N = 0;
    int head = 0;
    cin >> N >> head;

    for(int i = 0; i < N; i++) {
        int address = 0;
        cin >> address;
        cin >> lists[address].data >> lists[address].next;
        lists[address].address = address;
    }

    // Check validation
    int current = head;
    int total = 0;
    while(current != -1) {
        valids[total++] = lists[current];
        current = lists[current].next;
    }

    if(total == 0) {
        printf("0 -1");
        return 0;
    }

    sort(valids, valids + total, dataCompare);

    int i = 0;
    printf("%d %05d\n", total, valids[i].address);
    for(; i < total - 1; i++) {
        printf("%05d %d %05d\n", valids[i].address, valids[i].data, valids[i + 1].address);
    }

    printf("%05d %d %d", valids[i].address, valids[i].data, -1);
    return 0;
}
