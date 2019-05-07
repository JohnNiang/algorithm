#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 0, b = 0;
    int flag = 0;
    while(scanf("%d %d", &a, &b) != EOF) {
        if(a == 0 || b == 0) {
            continue;
        }
        if(flag) {
            printf(" ");
        }
        printf("%d %d", a * b, b - 1);

        flag = 1;
    }

    if(!flag) {
        printf("0 0");
    }
    return 0;
}
