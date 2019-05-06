#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 54

int visits[SIZE] = {0};

char map[5] = {'S', 'H', 'C', 'D', 'J'};

void swap(int* left, int* right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

int main() {
    int cards[SIZE] = {0};
//    printf("Initization:\n");
    for(int i = 0; i < SIZE; i++) {
        cards[i] = i;
//        printf("%d\n", cards[i]);
    }
    // Input repeat times
    int repeatTimes = 0;
    scanf("%d", &repeatTimes);

//    printf("Repeat times: %d\n", repeatTimes);

    int order[SIZE] = {0};

//    printf("Order:\n");
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &order[i]);
        order[i]--;
//        printf("%d\n", order[i]);
    }

    for(int j = 0; j < repeatTimes; j++) {
        memset(visits, 0, SIZE * visits[0]);
        for(int i = 0; i < SIZE; i++) {
            if(visits[i] > 0) {
                continue;
            }

            visits[i] = 1;

            int k = order[i];
            while(k != i) {
                int temp = cards[i];
                cards[i] = cards[k];
                cards[k] = temp;
                visits[k] = 1;
                k = order[k];
            }
        }
    }

//    printf("Result:\n");
    for(int i = 0; i < SIZE; i++) {
        char prefix = map[cards[i] / 13];
        int num = cards[i] % 13 + 1;
        if(i != 0) {
            printf(" ");
        }
        printf("%c%d", prefix, num);
    }

    return 0;
}
