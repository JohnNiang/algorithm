#include <stdio.h>
#include <stdlib.h>

// B1002: 写出这个数
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805324509200384>

char *numbers[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
    char number[101] = {0};
    // Input number
    scanf("%s", number);

    char *digit = number;
    int sum = 0;
    while(*digit != '\0') {
        sum += (*digit) - '0';
        digit++;
    }
    int sumDigits[3] = {0};
    int k = 0;
    while(sum > 0) {
        int remain = sum % 10;
        sumDigits[k++] = remain;
        sum /= 10;
    }

    for(int i = k - 1; i >= 0; i--) {
        printf(numbers[sumDigits[i]]);
        if(i != 0) {
            printf(" ");
        }
    }

    return 0;
}
