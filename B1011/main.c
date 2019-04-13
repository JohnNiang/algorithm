#include <stdio.h>
#include <stdlib.h>

int main()
{
    long a = 0, b = 0, c = 0;
    int n = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%ld %ld %ld", &a, &b, &c);
        if (a + b > c) {
            printf("Case #%d: true\n", i);
        } else {
            printf("Case #%d: false\n", i);
        }
    }

    return 0;
}
