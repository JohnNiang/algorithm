#include <iostream>
#include <algorithm>

using namespace std;

// A1080: Graduate Admission
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805387268571136>

struct Student {
    int id;
    int examGrade;
    int inteGrade;
    int finalGrade;
    int choice[5];
    int rank;
} students[40000];

struct School {
    int quota;
    int total = 0;
    int ids[40000];
    int last = -1;
} schools[100];

bool compare(Student& l, Student& r) {
    if(l.finalGrade != r.finalGrade) {
        return l.finalGrade > r.finalGrade;
    }

    return l.examGrade > r.examGrade;
}

bool idCompare(int l, int r) {
    return l < r;
}

int main() {
    int N = 0; // Total number of applicants
    int M = 0; // Total number of graduate schools
    int K = 0; // The number of choices
    cin >> N >> M >> K;

    for(int i = 0; i < M; i++) {
        cin >> schools[i].quota;
    }

    for(int i = 0; i < N; i++) {
        students[i].id = i;
        cin >> students[i].examGrade >> students[i].inteGrade;
        students[i].finalGrade = students[i].examGrade + students[i].inteGrade;
        for(int j = 0; j < K; j++) {
            cin >> students[i].choice[j];
        }
    }

    // Sort it
    sort(students, students + N, compare);

    // Rank those students
    for(int i = 0; i < N; i++) {
        students[i].rank = i;
        if(i > 0 &&
                students[i].finalGrade == students[i - 1].finalGrade &&
                students[i].examGrade == students[i - 1].examGrade) {
            students[i].rank = students[i - 1].rank;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int k = 0; k < K; k++) {
            int choice = students[i].choice[k];
            int total = schools[choice].total;
            int last = schools[choice].last;
            if(total < schools[choice].quota ||
                    (last != -1 && students[last].rank == students[i].rank)) {
                schools[choice].ids[total] = students[i].id;
                schools[choice].last = i;
                schools[choice].total++;
                break;
            }
        }
    }

    for(int m = 0; m < M; m++) {
        if(schools[m].total == 0) {
            cout << endl;
            continue;
        }

        sort(schools[m].ids, schools[m].ids + schools[m].total, idCompare);

        for(int i = 0; i < schools[m].total; i++) {
            if(i != 0) {
                cout << " ";
            }
            cout << schools[m].ids[i];
        }
        cout << endl;
    }

    return 0;
}
