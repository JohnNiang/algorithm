#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// A1031: Hello World for U
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805462535356416>

int main() {
    // Input text
    char text[81];
    printf("%d", ceil(4.0));
    scanf("%s", text);

    // Get N
    int N = 0;
    N = strlen(text);

    int n1 = 0;
    int n2 = 0;
    int n3 = 0;

    // Calculate n2, n1 and n3
    n1 = n3 = (N + 2) / 3;
    n2 = N + 2 - n1 - n3;

//    printf("n1 = %d, n2 = %d, n3 = %d\n", n1, n2, n3);

    // Print pattern
    for(int i = 0; i < n1 - 1; i++) {

        // Print first char
        printf("%c", text[i]);

        // Print white space
        for(int j = 1; j < n2 - 1; j++) {
            printf(" ");
        }

        // Print last char
        printf("%c\n", text[N - i - 1]);
    }

    for(int i = 0; i < n2; i++) {
        printf("%c", text[n1 - 1 + i]);
    }
    return 0;
}
