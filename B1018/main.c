#include <stdio.h>
#include <stdlib.h>

int convert(char ch)
{
    return ch == 'B' ? 0 : ch == 'C' ? 1 : 2;
}

int judge(int left, int right)
{
    if(left == right)
    {
        return 0;
    }

    if((left + 1) % 3 == right)
    {
        return 1;
    }

    return -1;
}

int printMax(int* arr) {
 return 0;
}

int main()
{
    char map[3] = {'B', 'C', 'J'};
    int n = 0;
    scanf("%d", &n);

    int aResult[3] = {0};
    int bResult[3] = {0};
    int aDraw[3] = {0};
    int bDraw[3] = {0};

    for(int i = 0; i < n; i++)
    {
        char a = '\0', b = '\0';
        scanf(" %c", &a);
        scanf(" %c", &b);
        int left = convert(a);
        int right = convert(b);

        int result = judge(left, right);
        if(result == 0)
        {
            aResult[1] ++;
            bResult[1] ++;
        }
        else if (result == -1)
        {
            aResult[2]++;
            bResult[0]++;
            bDraw[right]++;
        }
        else if (result == 1)
        {
            aResult[0]++;
            bResult[2]++;
            aDraw[left]++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            printf("%d", aResult[i]);
        }
        else
        {
            printf(" %d", aResult[i]);
        }
    }

    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            printf("%d", bResult[i]);
        }
        else
        {
            printf(" %d", bResult[i]);
        }
    }

    printf("\n");

    int max = 0;

    for (int i = 0; i < 3; i++) {
        if (aDraw[i] > max)
            max = aDraw[i];
    }

    for (int i = 0; i < 3; i++) {
        if (aDraw[i] == max) {
            printf("%c", map[i]);
            break;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (bDraw[i] > max)
            max = bDraw[i];
    }

    for (int i = 0; i < 3; i++) {
        if (bDraw[i] == max) {
            printf(" %c", map[i]);
            break;
        }
    }

    return 0;
}
