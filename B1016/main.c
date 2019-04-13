#include <stdio.h>
#include <stdlib.h>

long calculateDsum(long n, int d)
{
    int sum = 0;
    while (n > 0) {
        int remain = n % 10;
        if(remain == d) {
            sum = sum * 10 + d;
        }
        n /= 10;
    }
    return sum;
}

int main()
{
    long a = 0, b = 0;
    int da = 0, db = 0;
    scanf("%ld %d %ld %d", &a, &da, &b, &db);
    long pa = calculateDsum(a, da);
    long pb = calculateDsum(b, db);
    printf("%ld", pa + pb);
    return 0;
}
