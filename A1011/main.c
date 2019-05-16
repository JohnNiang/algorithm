#include <stdio.h>
#include <stdlib.h>

// A1011: World Cup Betting
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805504927186944>
int main() {
    char result[3] = {'W', 'T', 'L'};
    float number[3] = {0};
    float max[3] = {0};
    float total = 1.0;
    for(int i = 0; i < 3; i++) {
        scanf("%f %f %f", &number[0], &number[1], &number[2]);
        int maxIdx = 0;
        for(int j = 0; j < 3; j++) {
            if(number[j] > max[i]) {
                max[i] = number[j];
                maxIdx = j;
            }
        }
        printf("%c ", result[maxIdx]);

        total *= max[i];
    }

    // Calculate the result
    printf("%.2f", (total * 0.65 - 1) * 2);
    return 0;
}
