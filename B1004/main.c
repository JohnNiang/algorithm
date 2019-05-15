#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[11];
    char number[11];
    int grade;
};
int main() {
    // Input n
    int n = 0;
    scanf("%d", &n);

    struct Student stageStudent = {"", "", -1};
    struct Student minGradeStudent = {"", "", 101};
    struct Student maxGradeStudent = {"", "", -1};

    for(int i = 0; i < n; i++) {
        scanf("%s %s %d", stageStudent.name, stageStudent.number, &stageStudent.grade);
        if(stageStudent.grade > maxGradeStudent.grade) {
            strcpy(maxGradeStudent.name, stageStudent.name);
            strcpy(maxGradeStudent.number, stageStudent.number);
            maxGradeStudent.grade = stageStudent.grade;
        }

        if(minGradeStudent.grade == -1 || stageStudent.grade < minGradeStudent.grade) {
            strcpy(minGradeStudent.name, stageStudent.name);
            strcpy(minGradeStudent.number, stageStudent.number);
            minGradeStudent.grade = stageStudent.grade;
        }
    }

    printf("%s %s\n", maxGradeStudent.name, maxGradeStudent.number);
    printf("%s %s", minGradeStudent.name, minGradeStudent.number);

    return 0;
}
