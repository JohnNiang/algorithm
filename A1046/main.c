#include <stdio.h>
#include <stdlib.h>

int calculateShortest(int *distancesToFirst, int total, int totalDistance, int left, int right) {
    int leftToRightSum = *(distancesToFirst + left) - *(distancesToFirst + right);

    if(leftToRightSum < 0) {
        leftToRightSum *= -1;
    }

    int rightToLeftSum = totalDistance - leftToRightSum;

    return leftToRightSum < rightToLeftSum ? leftToRightSum : rightToLeftSum;
}

int main() {
    // Input N
    int N = 0;
    scanf("%d", &N);

    // Initialize distances array dynamically
    int *distancesToFirst = malloc((N + 1) * sizeof(*distancesToFirst));

    int totalDistance = 0;

    *distancesToFirst = 0;
    // Input distances
    for(int i = 0; i < N; i++) {
        int exit = 0;
        scanf("%d", &exit);
        totalDistance += exit;
        *(distancesToFirst + i + 1) = totalDistance;
    }

    // Input M
    int M = 0;
    scanf("%d", &M);

    // Input a pair of exit number
    for(int i = 0; i < M; i++) {
        int left = 0;
        int right = 0;
        scanf("%d %d", &left, &right);

        // Calculate the result and print
        int shortestDistance = calculateShortest(distancesToFirst, N, totalDistance, left - 1, right - 1);

        printf("%d\n", shortestDistance);
    }

    free(distancesToFirst);
    return 0;
}
