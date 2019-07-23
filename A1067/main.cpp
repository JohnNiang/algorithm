#include <iostream>
#include <algorithm>

using namespace std;

// A1067: Sort with Swap(0, i)
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805403651522560>

int numbers[100000];

int main() {
    int N = 0;
    scanf("%d", &N);

    int needSwap = N - 1;

    for(int i = 0; i < N; i++) {
        int number = 0;
        scanf("%d", &number);
        numbers[i] = number;
        if(number == i && number != 0) {
            needSwap --;
        }
    }

    int swapTimes = 0;
    int current = 1;
    while(needSwap > 0) {
        // If first position is 0
        if(numbers[0] == 0) {
            while(current < N) {
                if(numbers[current] != current) {
                    // Swap
                    swap(numbers[current], numbers[0]);
                    swapTimes ++;
                    break;
                }
                current ++;
            }
        }

        // If first position isn't 0
        while(numbers[0] != 0) {
            swap(numbers[0], numbers[numbers[0]]);
            swapTimes++;
            needSwap--;
        }
    }

    printf("%d", swapTimes);
    return 0;
}
