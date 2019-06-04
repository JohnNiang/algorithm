#include <stdio.h>
#include <stdlib.h>

// A1001: A+B Format
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805528788582400>

int main() {
    int a = 0;
    int b = 0;

    scanf("%d %d", &a, &b);

    int c = a + b;

    if(c < 0) {
        printf("-");
        c = -c;
    }

    char number[10] = {0};
    // Convert int to string
    int i = 0;
    while(c != 0) {
        int remain = c % 10;
        number[i++] = remain + '0';
        c /= 10;
    }

    if(i == 0) {
        printf("0");
    }

    // Get length of the number string
    int length = i;

    // Get start comma
    for(i = length - 1; i >= 0; i--) {
        printf("%c", number[i]);
        if(i != 0 && i % 3 == 0) {
            printf(",");
        }
    }
    return 0;
}
