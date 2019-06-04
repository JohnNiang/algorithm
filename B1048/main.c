#include <stdio.h>
#include <stdlib.h>

// B1048: 数字加密
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805276438282240>

const char radix[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};

int getLength(char *str) {
    if(str == NULL) {
        return 0;
    }
    char *ch = str;
    int length = 0;
    while(*ch++ != '\0') {
        length++;
    }
    return length;
}

int stringToInt(char *str) {
    int result = 0;
    char *ch = str;
    while(*ch != '\0') {
        result = result * 10 + (*ch++ - '0');
    }

    return result;
}

void reverse(char *str) {
    int length = getLength(str);
    for(int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char A[101] = {0};
    char B[101] = {0};

    scanf("%s %s", A, B);
//    printf("A=%s, B=%s\n", A, B);

    // Get A length
    int aLen = getLength(A);
//    printf("Length of A: %d\n", aLen);

    // Get B length
    int bLen = getLength(B);
//    printf("Lenght of B: %d\n", bLen);

    char result[101] = {0};

    // Reverse A and B
    reverse(A);
    reverse(B);

//    printf("Reverse A: %s\n", A);
//    printf("Reverse B: %s\n", B);
    int maxLength = aLen > bLen ? aLen : bLen;
    for(int i = 0; i < maxLength; i++) {
        int a = i < aLen ? (A[i] - '0') : 0;
        int b = i < bLen ? (B[i] - '0') : 0;

        if((i + 1) % 2 == 1) {
            int odd = (a + b) % 13;
            // Odd
            result[i] = radix[odd];
        } else {
            // Even
            int even = b - a;
            even = even < 0 ? (even + 10) : even;
            result[i] = '0' + even;
        }
    }

    // Reverse result
    reverse(result);

    printf(result);

    return 0;
}

