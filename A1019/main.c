#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A1019: General Palindromic Number
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805487143337984>
int main() {
    int N = 0;
    int b = 0;
    scanf("%d %d", &N, &b);
//    printf("N = %d, b = %d\n", N, b);

    // Convert the N
    int digits[32] = {0};
    int k = 0;
    while(N >= b) {
        digits[k++] = N % b;
        N /= b;
    }

    digits[k] = N;

    bool isPalindromic = true;
    for(int i = k; i > k / 2; i--) {
        if(digits[i] != digits[k - i]) {
            isPalindromic = false;
            break;
        }
    }

    printf(isPalindromic ? "Yes\n" : "No\n");

    for(int i = k; i >= 0; i--) {
        if(i != k) {
            printf(" ");
        }

        printf("%d", digits[i]);
    }

    return 0;
}
