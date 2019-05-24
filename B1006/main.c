#include <stdio.h>
#include <stdlib.h>

// B1006: 换个格式输出整数
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805318855278592>
int main() {
    int n = 0;
    scanf("%d", &n);

    // Calculate B
    int b = n / 100;
    for(int i = 0; i < b; i++) {
        printf("%c", 'B');
    }
    int s = n % 100 / 10;
    for(int i = 0; i < s; i++) {
        printf("%c", 'S');
    }

    int d = n % 100 % 10;
    for(int i = 0; i < d; i++) {
        printf("%d", i + 1);
    }
    return 0;
}
