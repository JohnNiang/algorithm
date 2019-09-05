#include <iostream>
#include <algorithm>

using namespace std;

// A1074: Reversing Linked List
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805394512134144>

const int MAX = 100000;

struct LinkedList {
    int data;
    int next;
    int address;
} lists[MAX];

void print(LinkedList& list) {
    printf("%05d %d", list.address, list.data);
    if(list.next != -1) {
        printf(" %05d", list.next);
    } else {
        printf(" %d", list.next);
    }
    printf("\n");
}

void print(int head) {
    int current = head;
    while(current != -1) {
        LinkedList list = lists[current];
        print(list);
        current = list.next;
    }
}

int reverse(int head, int k) {
    if(head == -1) {
        return head;
    }
    int kNext = head;
    for(int i = 0; i < k; i++) {
        kNext = lists[kNext].next;
        if(kNext == -1 && i < k - 1) {
            return head;
        }
    }
    int current = head;
    int prev = kNext;
    while(current != kNext) {
        int next = lists[current].next;
        lists[current].next = prev;
        prev = current;
        current = next;
    }
    lists[head].next= reverse(kNext, k);
    return prev;
}

int main() {
    int head = 0;
    int N = 0;
    int K = 0;
    cin >> head >> N >> K;
    for(int i = 0; i < N; i++) {
        int address = 0;
        cin >> address;
        cin >> lists[address].data >> lists[address].next;
        lists[address].address = address;
    }
    head = reverse(head, K);
    print(head);
    return 0;
}

