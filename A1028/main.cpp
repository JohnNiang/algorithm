#include <iostream>
#include <string.h>
#include <cstdio>
#include <algorithm>

using namespace std;

// A1028: List Sorting
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805468327690240>

struct Student {
    char id[7];
    char name[9];
    int grade;
} students[100000];

bool idCompare(Student& left, Student& right) {
    return strcmp(left.id, right.id) < 0;
}

bool nameCompare(Student& left, Student& right) {
    int nameResult = strcmp(left.name, right.name);
    if(nameResult != 0) {
        return nameResult < 0;
    }
    return idCompare(left, right);
}

bool gradeCompare(Student& left, Student& right) {
    if(left.grade != right.grade) {
        return left.grade < right.grade;
    }

    return idCompare(left, right);
}

int main() {
    int N = 0;
    int C = 0;
    scanf("%d %d", &N, &C);

    for(int i = 0; i < N; i++) {
        scanf("%s %s %d", students[i].id, students[i].name, &students[i].grade);
    }

    if(C == 1) {
        sort(students, students + N, idCompare);
    } else if(C == 2) {
        sort(students,  students + N, nameCompare);
    } else if(C == 3) {
        sort(students,  students + N, gradeCompare);
    }

    for(int i = 0; i < N; i++) {
        printf("%s %s %d\n", students[i].id, students[i].name, students[i].grade);
    }

    return 0;
}
