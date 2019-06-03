#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A1073: Scientific Notation
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805395707510784>

// Cases:
// +3.1415E+004
// -3.1415926E+4
// +3.1415926E-01
// -3.1415926E-0005

int main() {
    char number[10001] = {0};
    scanf("%s", number);

    // Get string length
    char *current = number;
    int length = 0;
    while(*current++ != '\0') {
        length++;
    }

    // Find 'E' position
    int ePos = 0;
    for(int i = 0; i < length; i++) {
        if(number[i] == 'E') {
            ePos = i;
            break;
        }
    }

    // Calc the exponent
    int exp = 0;
    for(int i = ePos + 2; i < length; i++) {
        exp = exp * 10 + (number[i] - '0');
    }

    if(number[0] == '-') {
        printf("-");
    }

    if(exp == 0) {
        for(int i = 1; i < ePos; i++) {
            printf("%c", number[i]);
        }
        return 0;
    }

    if(number[ePos + 1] == '+') {
        // If the exponent is positive
        for(int i = 1; i < ePos; i++) {
            if(number[i] == '.') {
                continue;
            }

            if(i == exp + 3) {
                printf(".");
            }

            printf("%c", number[i]);
        }

        if(exp + 2 >= ePos) {
            for(int i = ePos; i <= exp + 2; i++) {
                printf("0");
            }
        }
    } else {
        // Otherwise
        for(int i = 0; i < exp; i++) {
            printf("0");
            if(i == 0) {
                printf(".");
            }
        }

        for(int i = 1; i < ePos; i++) {
            if(number[i] == '.') {
                continue;
            }
            printf("%c", number[i]);
        }
    }

    return 0;
}
