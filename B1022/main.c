#include <stdio.h>
#include <stdlib.h>

// B1022: D进制的A+B
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805299301433344>

int main() {
    // Input A,B and D
    int A = 0;
    int B = 0;
    int D = 0;
    scanf("%d %d %d", &A, &B, &D);

    int C = A + B;

//    printf("A + B = %d, radix: %d\n", C, D);

    int numbers[32] = {0};

    int i = 0;
    while(C >= D) {
        numbers[i++] = C % D;
        C /= D;
    }

    numbers[i] = C;

    for(int j = i; j >= 0; j--) {
        printf("%d", numbers[j]);
    }

    return 0;
}
