#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// B1014: 福尔摩斯的约会
// https://pintia.cn/problem-sets/994805260223102976/problems/994805308755394560

char *days[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

bool isAlphabet(char ch) {
    return (ch >= 'a' && ch <=  'z') || (ch >=  'A' && ch <=  'Z');
}

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isDayChar(char ch) {
    return ch >= 'A' && ch <= 'G';
}

bool isHourChar(char ch) {
    return isDigit(ch) || (ch >= 'A' && ch <= 'N');
}

int main() {
    char appointments[4][61] = {0};
    for(int i = 0; i < 4; i++) {
        scanf("%s", appointments[i]);
    }

    // Compare first two strings
    char *first = appointments[0];
    char *second = appointments[1];

    char commonFirst = 0;
    char commonSecond = 0;

    while(*first != '\0' && *second != '\0') {
        if(*first == *second) {
            // Handle second common
            if(isHourChar(*first) && commonFirst != 0 && commonSecond == 0) {
                commonSecond = *first;
            }

            // Hanlde first common
            if(isDayChar(*first) && commonFirst == 0) {
                commonFirst = *first;
            }
        }

        first ++;
        second ++;
    }

//    printf("first common: %c\n", commonFirst);
//    printf("second common: %c\n", commonSecond);

    // Compare last two strings
    first = appointments[2];
    second = appointments[3];

    int commonIndex = 0;

    while(*first != '\0' && *second != '\0') {
        bool equals = false;

        if(*first == *second && isAlphabet(*first)) {
            equals = true;
        }

        if(equals) {
            break;
        }

        first ++;
        second ++;
        commonIndex ++;
    }

//    printf("last two strings common index: %d\n", commonIndex);
    int hour = 0;
    if(isDigit(commonSecond)) {
        hour = commonSecond - '0';
    } else {
        hour = commonSecond - 'A' + 10;
    }

    printf("%s %02d:%02d", days[commonFirst - 'A'], hour, commonIndex);

    return 0;
}
