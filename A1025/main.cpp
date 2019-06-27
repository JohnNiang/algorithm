#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

// A1025: PAT Rannumbering
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805474338127872>

struct Testee {
    long regNum;
    int score;
    int locNum;
    int localRank;
} testees[30000];

bool compare(Testee &left, Testee &right) {
    if(left.score != right.score) {
        return left.score > right.score;
    }

    return left.regNum <= right.regNum;
}

int main() {
    // Total number of Location
    int N = 0;
    scanf("%d", &N);

    // Total number of testee
    int number = 0;
    for(int i = 1; i <= N; i++) {
        // Number of the testee
        int K = 0;
        scanf("%d", &K);

        for(int j = 0; j < K; j++, number++) {
            scanf("%ld %d", &testees[number].regNum, &testees[number].score);
            testees[number].locNum = i;
        }

        // Sort the testee
        sort(testees + (number - K), testees + number, compare);

        for(int m = number - K, n = 1; m < number; m++, n++) {
            testees[m].localRank = n;
            if(m > number - K && testees[m].score == testees[m - 1].score) {
                testees[m].localRank = testees[m - 1].localRank;
            }
        }
    }

    sort(testees, testees + number, compare);

    printf("%d\n", number);

    for(int i = 0, r = 1; i < number; i++) {
        if(i > 0 && testees[i].score != testees[i - 1].score) {
            r = i + 1;
        }

        printf("%ld %d %d %d\n", testees[i].regNum, r, testees[i].locNum, testees[i].localRank);
    }

    return 0;
}
