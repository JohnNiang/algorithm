#include <stdio.h>
#include <stdlib.h>

#define CLK_TCK 100

int main()
{
    int c1 = 0, c2 = 0;
    scanf("%d %d", &c1, &c2);
    int remain = (c2 - c1);
    if(remain % CLK_TCK < 50) {
        remain = remain / CLK_TCK;
    } else {
        remain = remain / CLK_TCK + 1;
    }
    int hour = remain / 3600;
    int minute = remain % 3600 / 60;
    int second = remain % 60;
    printf("%02d:%02d:%02d", hour, minute, second);
    return 0;
}
