#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// B1015: 德才论
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805307551629312>

struct Student {
    char no[9];
    int vertue;
    int ability;
    int total;
    int level;
    // 1: vertue and ablitity >= H
    // 2: ability < H && vertue >= H
    // 3: ability < H && vertue < H && vertue >= ability
    // 4: others
} students[100000];

int compare(const void* left, const void* right) {
    struct Student* leftStu = (struct Student*)left;
    struct Student* rightStu = (struct Student*)right;

    if(leftStu->level != rightStu->level) {
        return leftStu->level - rightStu->level;
    }

    if(leftStu->total != rightStu->total) {
        return rightStu->total - leftStu->total;
    }

    if(leftStu->vertue != rightStu->vertue) {
        return rightStu->vertue - leftStu->vertue;
    }

    return strcmp(leftStu->no, rightStu->no) < 0;
}

void printStudents(int m) {
    for(int i = 0; i < m; i++) {
        printf("%s %d %d\n", students[i].no, students[i].vertue, students[i].ability);
    }
}

int main() {

    int N = 0;
    int L = 0;
    int H = 0;

    scanf("%d %d %d", &N, &L, &H);

    int M = N;

    for(int i = 0; i < N; i++) {
        scanf("%s %d %d", students[i].no, &students[i].vertue, &students[i].ability);
        if(students[i].vertue < L || students[i].ability < L) {
            students[i].level = 4;
            M--;
        } else if(students[i].vertue >= H && students[i].ability >= H) {
            students[i].level = 1;
        } else if(students[i].ability < H && students[i].vertue >= H) {
            students[i].level = 2;
        } else if(students[i].vertue < H && students[i].ability < H && students[i].vertue >= students[i].ability) {
            students[i].level = 3;
        } else {
            students[i].level = 4;
        }

        students[i].total = students[i].vertue + students[i].ability;
    }

    // Sort the students
    qsort(students, N, sizeof(students[0]), compare);

    printf("%d\n", M);
    printStudents(M);
    return 0;
}

