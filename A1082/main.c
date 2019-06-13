#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A1080: Read Number in Chinese
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805385053978624>

const char *digitMap[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

const char *baseUnitMap[4] = {"", "Shi", "Bai", "Qian"};
const char *bigUnitMap[3] = {"", "Wan", "Yi"};

bool isEnd(char ch) {
    return ch == '\0';
}

int getLength(char *str) {
    char *p = str;
    int length = 0;
    while(!isEnd(*p)) {
        length++;
        p++;
    }
    return length;
}

int main() {
    char numberString[11] = {0};
    scanf("%s", numberString);

    // Get length
    int length = getLength(numberString);

    char *numberPtr = numberString;

    if(numberString[0] == '-') {
        printf("Fu ");
        numberPtr++;
        length--;
    }

    bool isZero = true;
    int k = 0;
    for(; k < length; k++) {
        if(numberPtr[k] != '0') {
            isZero = false;
            break;
        }
    }


    if(isZero) {
        printf(digitMap[0]);
        return 0;
    }


    for(int i = k; i < length; i++) {
        int digit = numberPtr[i] - '0';

        if(i != k && digit != 0) {
            printf(" ");
        }

        // Print with unit
        int remain = (length - 1 - i) % 4;

        if(remain == 0) {
            int quotient = (length - 1 - i) / 4;

            if(digit == 0) {
                if((length - 1) / 4 < 2 && quotient == 1) {
                    printf(" %s", bigUnitMap[quotient]);
                }
            } else {
                if(quotient == 0) {
                    printf(digitMap[digit]);
                } else {
                    if(i != 0 && remain != 3 && numberPtr[i - 1] == '0') {
                        printf("ling ");
                    }
                    printf("%s %s", digitMap[digit], bigUnitMap[quotient]);
                }
            }
        } else {
            if(digit != 0) {
                if(i != 0 && remain != 3 && numberPtr[i - 1] == '0') {
                    printf("ling ");
                }
                printf("%s %s", digitMap[digit], baseUnitMap[remain]);
            }
        }
    }
    return 0;
}
