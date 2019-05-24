#include <stdio.h>
#include <stdlib.h>

// B1021: 个位数统计
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805300404535296>

int main() {
    char number[1001] = {0};
    scanf("%s", number);

    int digits[10] = {0};

    char *ch = number;

    while(*ch != '\0') {
        char digit = *ch;
        digits[digit - '0']++;
        ch++;
    }

    for(int i = 0; i < 10; i++) {
        if(digits[i] != 0) {
            printf("%d:%d\n", i, digits[i]);
        }
    }


    return 0;
}
