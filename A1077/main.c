#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A1077: Kuchiguse
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805390896644096>

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

void reverse(char *str) {
    int length = getLength(str);
    for(int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

int main() {
    int N = 0;
    scanf("%d", &N);
    getchar(); // Filter the line break

    char lines[100][257] = {0};

    for(int i = 0; i < N; i++) {
        gets(lines[i]);
        // Reverse line
        reverse(lines[i]);
    }

    int suffixLength = 0;
    for(int i = 0; i < 257; i++) {
        bool common = true;
        char temp = lines[0][i];

        if(isEnd(temp)) {
            break;
        }

        for(int j = 1; j < N; j++) {
            if(isEnd(lines[j][i]) || temp != lines[j][i]) {
                common = false;
                break;
            }
        }

        if(common) {
            suffixLength++;
        } else {
            break;
        }
    }

    if(suffixLength == 0) {
        printf("nai");
    } else {
        for(int i = suffixLength - 1; i >= 0; i--) {
            printf("%c", lines[0][i]);
        }
    }

    return 0;
}
