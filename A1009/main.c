#include <stdio.h>
#include <stdlib.h>

// Product of Polynomials

int main() {
    // Input A
    int AK = 0;
    float Aa[1001] = {0};
    int aMax = 0;

    scanf("%d", &AK);
    for(int i = 0; i < AK; i++) {
        int N = 0;
        float aN = 0;
        scanf("%d %f", &N, &aN);
        Aa[N] = aN;

        if(N > aMax) {
            aMax = N;
        }
    }

    float result[2001] = {0};
    int max = 0;
    int total = 0;

    // Input B
    int BK = 0;

    scanf("%d", &BK);

    for(int i = 0; i < BK; i++) {
        int N = 0;
        float bN = 0;
        scanf("%d %f", &N, &bN);
        for(int j = 0; j <= aMax; j++) {
            float aN = Aa[j];
            if(aN == 0.0) {
                continue;
            }
            int resultN = N + j;
            result[resultN] += aN * bN;
            if(resultN > max) {
                max = resultN;
            }
        }
    }

    for(int i = max; i >= 0; i--) {
        if(result[i] != 0.0) {
            total ++;
        }
    }

    printf("%d", total);

    for(int i = max; i >= 0; i--) {
        if(result[i] != 0.0) {
            printf(" %d %.1f", i, result[i]);
        }
    }

    return 0;
}
