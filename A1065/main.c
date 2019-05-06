#include <stdio.h>
#include <stdlib.h>

int main() {
    int T = 0;
    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        long long a = 0;
        long long b = 0;
        long long c = 0;

        scanf("%lld %lld %lld", &a, &b, &c);

        int result = 0;

        long long addition = a + b;

        if(a > 0 && b > 0 && addition < 0) {
            result = 1;
        } else if(a < 0 && b < 0 && addition >= 0) {
            result = 0;
        } else if(addition > c) {
            result = 1;
        } else {
            result = 0;
        }

//        printf("result=%d\n", result);

        printf("Case #%d: %s\n", i + 1, result == 1 ? "true" : "false");
    }
    return 0;
}
