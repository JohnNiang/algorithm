#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 0;
    int ad = 0, bd = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int a1 = 0, a2 =0, b1 = 0, b2 = 0;
        scanf("%d %d %d %d", &a1, &a2, &b1, &b2);

        int sum = a1 + b1;

        if(sum == a2 && sum != b2) {
            bd ++;
        } else if(sum != a2 && sum == b2) {
            ad ++;
        }
    }

    printf("%d %d", ad, bd);
    return 0;
}
