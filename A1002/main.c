#include <stdio.h>
#include <stdlib.h>

int main() {
    // Input A
    int AK = 0;
    float Aa[1001] = {0};

    scanf("%d", &AK);
    for(int i = 0; i < AK; i++) {
        int N = 0;
        float aN = 0;
        scanf("%d %f", &N, &aN);
        Aa[N] = aN;
    }

    // Input B
    int BK = 0;
    float Ba[1001] = {0};

    scanf("%d", &BK);

    for(int i = 0; i < BK; i++) {
        int N = 0;
        float aN = 0;
        scanf("%d %f", &N, &aN);
        Ba[N] = aN;
    }

    float resulta[1001] = {0};

    int resultK = 0;
    int max = -1;
    for(int i = 1000; i >= 0; i--) {
        resulta[i] = Aa[i] + Ba[i];
        if(resulta[i]) {
            resultK++;

            if(max == -1) {
                max = i;
            }
        }
    }

    printf("%d", resultK);

    for(int i = max; i >= 0; i--) {
        if(resulta[i]) {
            printf(" %d %.1f", i, resulta[i]);
        }
    }

    return 0;
}
