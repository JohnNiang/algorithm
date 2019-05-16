#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// B1027: 打印沙漏
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805294251491328>

void printRow(int row, int n, char ch) {
    int blankCol = (n - row) / 2;
    for(int i = 0; i < blankCol; i++) {
        printf(" ");
    }
    for(int i = blankCol; i < blankCol + row; i++) {
        printf("%c", ch);
    }
//  Will cause 	Presentation Error
//    for(int i = blankCol + row; i < n; i++) {
//        printf(" ");
//    }

    printf("\n");
}
int main() {
    int N = 0;
    char ch;
    scanf("%d %c", &N, &ch);

    // Calculate the max n
    int n = floor(sqrt(2 * (N + 1)) - 1);
    if(n % 2 == 0) {
        n--;
    }

    int remain = N - ((n + 1) * (n + 1) / 2 - 1);
//    printf("n: %d, remain: %d\n", n, remain);

    // Print the pattern
    for(int i = n; i > 0; i -= 2) {
        printRow(i, n, ch);
    }

    for(int i = 3; i <= n; i += 2) {
        printRow(i, n, ch);
    }

    printf("%d", remain);
    return 0;
}
