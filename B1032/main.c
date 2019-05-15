#include <stdio.h>
#include <stdlib.h>

// B1032: 挖掘机技术哪家强
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805289432236032>

#define MAX 100001

struct Participant {
    int schNo;
    int score;
} temp;

int main() {
    // Which stores scores
    int school[MAX] = {0};
    // Input N
    int N = 0;
    scanf("%d", &N);

    int maxSchool = 0;
    int maxScore = -1;

    for(int i = 0; i < N; i++) {
        scanf("%d %d", &temp.schNo, &temp.score);

        school[temp.schNo] += temp.score;

        if(school[temp.schNo] > maxScore) {
            maxSchool = temp.schNo;
            maxScore  = school[maxSchool];
        }
    }

    if(maxSchool != 0) {
        printf("%d %d", maxSchool, school[maxSchool]);
    }

    return 0;
}
