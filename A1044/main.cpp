#include <iostream>

using namespace std;

// A1044: Shopping in Mars
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805439202443264>

const int MAX_N = 100000;
int diamonds[MAX_N] = { 0 };

int sums[MAX_N] = { 0 };

int binarySearch(int left, int right, int maxValue) {
    while(left < right) {
        int middle = (left + right) / 2;
        if(sums[middle] >= maxValue) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }

    return left;
}

int main() {
    int N = 0; // N <= 10^5
    int M = 0; // M <= 10^8
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> diamonds[i];
        if(i == 0) {
            sums[i] = diamonds[i];
        } else {
            sums[i] = sums[i - 1] + diamonds[i];
        }
    }

    int nearestM = 100000001;
    for(int i = 0; i < N; i++) {
        int j = binarySearch(i, N, sums[i] - diamonds[i] + M);
        int distance = sums[j] - (sums[i] - diamonds[i]);
        if(distance == M) {
            nearestM = M;
            break;
        }
        if(j < N && distance < nearestM) {
            nearestM = distance;
        }
    }

    for(int i = 0; i < N; i++) {
        int j = binarySearch(i, N, sums[i] - diamonds[i] + nearestM);
        int distance = sums[j] - (sums[i] - diamonds[i]);
        if(distance == nearestM) {
            cout << i + 1 << "-" << j + 1 << endl;
        }
    }

    return 0;
}
