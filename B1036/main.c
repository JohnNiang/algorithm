#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// B1036: 跟奥巴马一起编程
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805285812551680>

int main() {
    // Input N
    int N = 0;
    char unit;
    scanf("%d %c", &N, &unit);

    // Calculate rows
    int rows = round(N / 2.0);

    for(int i = 0; i < N; i++) {
        printf("%c", unit);
    }

    printf("\n");

    for(int i = 1; i < rows - 1; i++) {
        printf("%c", unit);
        for(int j = 1; j < N - 1; j++) {
            printf(" ");
        }
        printf("%c", unit);
        printf("\n");
    }

    for(int i = 0; i < N; i++) {
        printf("%c", unit);
    }

    return 0;
}
