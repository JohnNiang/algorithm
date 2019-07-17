#include <iostream>
#include <algorithm>

using namespace std;

// B1005: 继续(3n+1)猜想
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805320306507776>

bool hashTable[10000];

int numbers[100];

bool numberCmp(int l, int r) {
    return l > r;
}

int main() {
    int K = 0;
    scanf("%d", &K);

    for(int i = 0; i < K; i++) {
        scanf("%d", &numbers[i]);

        int n = numbers[i];

        while(n > 1) {
            if(n % 2 == 0) {
                // Even
                n /= 2;
            } else {
                // Odd
                n = (3 * n + 1) / 2;
            }
            hashTable[n] = true;
        }
    }

    // Statistic the total number of key numbers
    int total = 0;
    for(int i = 0; i < K; i++) {
        if(!hashTable[numbers[i]]) {
            total ++;
        }
    }

    // Sort the numbers
    sort(numbers, numbers + K, numberCmp);

    for(int i = 0; i < K; i++) {
        if(!hashTable[numbers[i]]) {
            printf("%d", numbers[i]);
            total--;
            if(total != 0) {
                printf(" ");
            }
        }
    }

    return 0;
}
