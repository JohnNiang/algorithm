#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

// A1012:The Best Rank
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805502658068480>

struct Student {
    int id;
    int a;
    int c;
    int m;
    int e;
};

bool aCompare(Student& left, Student& right) {
    return left.a > right.a;
}

bool cCompare(Student& left, Student& right) {
    return left.c > right.c;
}

bool mCompare(Student& left, Student& right) {
    return left.m > right.m;
}

bool eCompare(Student& left, Student& right) {
    return left.e > right.e;
}

void print(Student* student, int length) {
//    for(int i = 0; i < length; i ++) {
//        cout << student->id << " " << student->c << " " << student->m << " " << student->e << " " << student->a << endl;
//        student++;
//    }
//    cout << endl;
}

const char courseMap[4] = {'A', 'C', 'M', 'E'};

int aRank[1000000] = {0};
int cRank[1000000] = {0};
int mRank[1000000] = {0};
int eRank[1000000] = {0};

int main() {
    int N;
    int M;
    cin >> N >> M;

    Student students[2001];

    for(int i = 0; i < N; i++) {
        cin >> students[i].id >> students[i].c >> students[i].m >> students[i].e;
        students[i].a = (students[i].c + students[i].m + students[i].e) / 3;
    }

    // Sort by a;
    sort(students, students + N, aCompare);

    print(students, N);

    for(int i = 0; i < N; i++) {
        // Handle the same rank
        if(i != 0 && students[i - 1].a == students[i].a) {
            aRank[students[i].id] = aRank[students[i - 1].id];
            continue;
        }
        aRank[students[i].id] = i + 1;
    }

    // Sort by c;
    sort(students, students + N, cCompare);

    print(students, N);

    for(int i = 0; i < N; i++) {
        // Handle the same rank
        if(i != 0 && students[i - 1].c == students[i].c) {
            cRank[students[i].id] = cRank[students[i - 1].id];
            continue;
        }
        cRank[students[i].id] = i + 1;
    }

    sort(students, students + N, mCompare);

    print(students, N);

    for(int i = 0; i < N; i++) {
        // Handle the same rank
        if(i != 0 && students[i - 1].m == students[i].m) {
            mRank[students[i].id] = mRank[students[i - 1].id];
            continue;
        }
        mRank[students[i].id] = i + 1;
    }

    sort(students, students + N, eCompare);

    print(students, N);

    for(int i = 0; i < N; i++) {
        // Handle the same rank
        if(i != 0 && students[i - 1].e == students[i].e) {
            eRank[students[i].id] = eRank[students[i - 1].id];
            continue;
        }
        eRank[students[i].id] = i + 1;
    }

    for(int i = 0; i < M; i++) {
        int id = 0;
        cin >> id;

        int a = aRank[id];
        int c = cRank[id];
        int m = mRank[id];
        int e = eRank[id];

        if(a == 0.0 || c == 0 || m == 0 || e == 0) {
            cout << "N/A" << endl;
            continue;
        }

        int k = 0;
        int min = a;
        if(c < min) {
            min = c;
            k = 1;
        }

        if(m < min) {
            min = m;
            k = 2;
        }

        if(e < min) {
            min = e;
            k = 3;
        }

        cout << min << " " << courseMap[k] << endl;
    }

    return 0;
}
