#include <iostream>

using namespace std;

// B1047: 编程团体赛
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805277163896832>

int teamScores[1001] = {0};
int main() {
    int N = 0;
    scanf("%d", &N);
    int bestTeamNo = 0;
    int bestScore = 0;
    for(int i = 0; i < N; i++) {
        int teamNo = 0;
        int memberNo = 0;
        int score = 0;
        scanf("%d-%d %d", &teamNo, &memberNo, &score);
        teamScores[teamNo] += score;
        if(teamScores[teamNo] > bestScore) {
            bestScore = teamScores[teamNo];
            bestTeamNo = teamNo;
        }
    }

    printf("%d %d", bestTeamNo, bestScore);
    return 0;
}
