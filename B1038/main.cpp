#include <iostream>
#include <string.h>

using namespace std;

// B1038: 旧键盘打字
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805288530460672>

// Note:
// 本题目相对来讲非常简单，仅仅需要一个能存储同成绩的学生人数的数组即可。

int grades[101] = {0};
int main() {
    int N = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int grade = 0;
        cin >> grade;
        grades[grade]++;
    }

    int K = 0;
    cin >> K;
    for(int i = 0; i < K; i++) {
        int queryGrade = 0;
        cin >> queryGrade;

        if(i != 0) {
            cout << " ";
        }
        cout << grades[queryGrade];
    }

    return 0;
}
