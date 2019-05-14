#include <stdio.h>
#include <stdlib.h>

// 1041 考试座位号 (15 point(s))
// https://pintia.cn/problem-sets/994805260223102976/problems/994805281567916032

struct info {
    long ticketNumber;
    int examTestNumber;
};

int main() {
    struct info infos[1001];

    // Input N
    int N = 0;
    scanf("%d", &N);

    // Input infos
    for(int i = 0; i < N; i++) {
        long ticketNumber = 0;
        int machineTestNumber = 0;
        int examTestNumber = 0;
        scanf("%ld %d %d", &ticketNumber, &machineTestNumber, &examTestNumber);
        infos[machineTestNumber].ticketNumber = ticketNumber;
        infos[machineTestNumber].examTestNumber = examTestNumber;
    }

    // Input M
    int M = 0;
    scanf("%d", &M);

    // Input machine numbers
    for(int i = 0; i < M; i++) {
        int machineNumber = 0;
        scanf("%d", &machineNumber);

        struct info info = infos[machineNumber];
        printf("%ld %d\n", info.ticketNumber, info.examTestNumber);
    }

    return 0;
}
