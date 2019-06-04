#include <stdio.h>
#include <stdlib.h>

// A1005: Spell It Right
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805519074574336>

const char *digitMap[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

// Print sum recursively.
void printSum(int n) {
    if(n / 10 == 0) {
        printf("%s", digitMap[n % 10]);
        return;
    }

    printSum(n / 10);

    printf(" %s", digitMap[n % 10]);
}

int main() {
    char N[101] = {0};
    scanf("%s", N);

    int sum = 0;
    char *ptr = N;
    while(*ptr != '\0') {
        sum += (*ptr++ - '0');
    }

//    printSum(sum);

    // sum < 999
    int sumDigits[4] = {0};

    int len = 0;
    if(sum == 0) {
        sumDigits[len++] = sum;
    }

    while(sum != 0) {
        sumDigits[len++] = sum % 10;
        sum /= 10;
    }

    for(int i = len - 1; i >= 0; i--) {
        if(i != len - 1) {
            printf(" ");
        }
        printf("%s", digitMap[sumDigits[i]]);
    }

    return 0;
}
