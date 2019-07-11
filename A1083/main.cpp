#include <iostream>
#include <algorithm>

using namespace std;

// A1083: List Grades
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805383929905152>

struct Student {
    char name[11];
    char id[11];
    int grade;
} students[100000];

bool gradeCompare(Student& l, Student& r) {
    return l.grade > r.grade;
}

int main() {
    int N = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> students[i].name >> students[i].id >> students[i].grade;
    }

    int grade1 = 0;
    int grade2 = 0;

    cin >> grade1 >> grade2;

    // Sort it
    sort(students, students + N, gradeCompare);

    bool isPrint = false;

    for(int i = 0; i < N; i++) {
        if(students[i].grade >= grade1 && students[i].grade <= grade2) {
            isPrint = true;
            cout << students[i].name << " " << students[i].id << endl;
        }
    }

    if(!isPrint) {
        cout << "NONE" << endl;
    }

    return 0;
}
