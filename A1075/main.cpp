#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

// A1075: PAT Judge
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805393241260032>

struct User {
    int id;
    int totalScore;
    int solved;
    bool shouldShow;
    int scores[6];
} users[10010];

int fullScore[6];

void init(int n) {
    for(int i = 1; i <= n; i++) {
        users[i].id = i;
        users[i].totalScore = 0;
        users[i].solved = 0;
        users[i].shouldShow = false;
        memset(users[i].scores, -1, sizeof(users[i].scores));
    }
}

bool compare(User& left, User& right) {
    if(left.totalScore != right.totalScore) {
        return left.totalScore > right.totalScore;
    }

    if(left.solved != right.solved) {
        return left.solved > right.solved;
    }

    return left.id < right.id;
}

int main() {
    int N = 0; // <= 10^4
    int K = 0; // <= 5
    int M = 0; // <= 10^5

    scanf("%d %d %d", &N, &K, &M);

    init(N);

    for(int i = 0; i < K; i++) {
        scanf("%d", &fullScore[i]);
    }

    for(int i = 0; i < M; i++) {
        int id = 0;
        int problemId = 0;
        int score = 0;

        scanf("%d %d %d", &id, &problemId, &score);

        if(score > -1) {
            users[id].shouldShow = true;
        }

        if(score == -1 && users[id].scores[problemId - 1] == -1) {
            users[id].scores[problemId - 1] = 0;
        }

        if(score == fullScore[problemId - 1]) {
            users[id].solved++;
        }

        if(score > users[id].scores[problemId - 1]) {
            users[id].scores[problemId - 1] = score;
        }
    }

    // Calc the total score
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < K; j++) {
            if(users[i].scores[j] >= 0) {
                users[i].totalScore += users[i].scores[j];
            }
        }
    }

    // Sort it
    sort(users + 1, users + N + 1, compare);

    int r = 1;

    for(int i = 1; i <= N; i++) {
        if(!users[i].shouldShow) {
            continue;
        }
        if(i > 1 && users[i].totalScore != users[i - 1].totalScore) {
            r = i;
        }

        printf("%d %.5d %d", r, users[i].id, users[i].totalScore);
        for(int j = 0; j < K; j++) {
            if(users[i].scores[j] == -1) {
                printf(" -");
            } else {
                printf(" %d", users[i].scores[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
