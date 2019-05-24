#include <stdio.h>
#include <stdlib.h>

// B1009: 说反话
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805314941992960>
// 没有使用 <string.h> 库解决此题目。涉及到字符串的操作还是比较生疏的，建议多加练习此类题目。

#define MAX_CHAR 81

int main() {
    char sentence[MAX_CHAR] = {0};
    // Input the sentence
    // fgets() ought to be used instead of gets() as fgets() makes sure that no more than MAX_LIMIT characters are read.
    fgets(sentence, MAX_CHAR, stdin);

//    printf(sentence);

    char words[41][MAX_CHAR] = {0};

    int k = 0;
    int j = 0;

    char *current = sentence;

    while(*current != '\0' && *current != '\n') {
        if(*current == ' ') {
            k++;
            j = 0;
            current++;
            continue;
        }
        words[k][j++] = *current++;
    }

    for(int i = k; i >= 0; i--) {
        printf(words[i]);
        if(i != 0) {
            printf(" ");
        }
    }

    return 0;
}
