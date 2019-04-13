#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[100] = {0};
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    m %= n;

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;

    for (int i = n - m; i < n; i++) {
        printf("%d", arr[i]);
        count ++;

        if(count < n) {
            printf(" ");
        }
    }

    for (int i = 0; i < n - m; i++) {
        printf("%d", arr[i]);
        count ++;

        if(count < n) {
            printf(" ");
        }
    }
    return 0;
}
