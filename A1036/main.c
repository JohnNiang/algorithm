#include <stdio.h>
#include <stdlib.h>

// A1036: Boys vs Girls
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805453203030016>

struct Student {
    char name[11];
    char gender;
    char id[11];
    int grade;
} temp, lowestMale, highestFemale;

int main() {

    // Input N
    int N = 0;
    scanf("%d", &N);
    int hasLowestMale = 0;
    int hasHighestFemale = 0;
    for(int i = 0; i < N; i++) {
        scanf("%s %c %s %d", temp.name, &temp.gender, temp.id, &temp.grade);
        if(temp.gender == 'M') {
            // Male
            if(!hasLowestMale) {
                lowestMale = temp;
                hasLowestMale = 1;
            }

            // Compare grade
            if(temp.grade < lowestMale.grade) {
                lowestMale = temp;
            }
        } else if(temp.gender == 'F') {
            // Female
            if(!hasHighestFemale) {
                highestFemale = temp;
                hasHighestFemale = 1;
            }

            // Compare grade
            if(temp.grade > highestFemale.grade) {
                highestFemale = temp;
            }
        }
    }

    if(!hasHighestFemale) {
        printf("Absent\n");
    } else {
        printf("%s %s\n", highestFemale.name, highestFemale.id);
    }

    if(!hasLowestMale) {
        printf("Absent\n");
    } else {
        printf("%s %s\n", lowestMale.name, lowestMale.id);
    }

    if(hasLowestMale && hasHighestFemale) {
        printf("%d", highestFemale.grade - lowestMale.grade);
    } else {
        printf("NA");
    }

    return 0;
}
