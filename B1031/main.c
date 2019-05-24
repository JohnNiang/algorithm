#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// B1031: 查验身份证
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805290334011392>

const int priority[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

const char M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

bool isValid(char id[18]) {
    int sum = 0;
    for(int i = 0; i < 17; i++) {
        if(id[i] < '0' || id[i] > '9') {
            return false;
        }
        sum += ((id[i] - '0') * priority[i]);
    }

    int z = sum % 11;

    char m = M[z];

    return m == id[17];
}

int main() {
    int N = 0;
    scanf("%d", &N);

    bool allPassed = true;
    for(int i = 0; i < N; i++) {
        char id[18] = {0};
        scanf("%s", id);
        bool valid = isValid(id);
        if(!valid) {
            allPassed = false;
            printf("%s\n", id);
        }
    }

    if(allPassed) {
        printf("All passed");
    }

    return 0;
}
