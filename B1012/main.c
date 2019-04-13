#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count[5] = {0};
    int a[5] = {0};

    int N = 0;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        int number = 0;
        scanf("%d", &number);
        // A1
        if(number % 5 == 0)
        {
            if(number % 2 == 0)
            {
                a[0] += number;
                count[0] ++;
            }
        }
        else if(number % 5 == 1)
        {
            if (count[1] % 2 == 0)
            {
                a[1] += number;
            }
            else
            {
                a[1] -= number;
            }

            count[1]++;

        }
        else if(number % 5 == 2)
        {
            a[2] ++;
            count[2]++;
        }
        else if(number % 5 == 3)
        {
            a[3] += number;
            count[3] ++;
        }
        else if(number % 5 == 4)
        {
            if(number > a[4])
            {
                a[4] = number;
            }
            count[4] ++;
        }
    }
    if(count[0] == 0)
    {
        printf("N ");
    }
    else
    {
        printf("%d ", a[0]);
    }

    if(count[1] == 0)
    {
        printf("N ");
    }
    else
    {
        printf("%d ", a[1]);
    }

    if(count[2] == 0)
    {
        printf("N ");
    }
    else
    {
        printf("%d ", a[2]);
    }

    if(count[3] == 0)
    {
        printf("N ");
    }
    else
    {
        printf("%.1f ", (double)a[3] / count[3]);
    }

    if(count[4] == 0)
    {
        printf("N");
    }
    else
    {
        printf("%d", a[4]);
    }
    return 0;
}
