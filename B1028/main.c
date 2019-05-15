#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

// B1028：人口普查
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805293282607104>
//
//int isValid(int year, int month, int day) {
//    if(year > 2014 || year < 1814) {
//        return 0;
//    }
//
//    if((year == 2014 && month > 9) ||
//            (year == 1814 && month < 9)) {
//        return 0;
//    }
//
//    if((year == 2014 && month == 9 && day > 6) ||
//            (year == 1814 && month == 9 && day < 6)) {
//        return 0;
//    }
//
//    return 1;
//}
//
//int main() {
//    // Input N
//    int N = 0;
//    scanf("%d", &N);
//
//    int maxYear = 1814;
//    int maxMonth = 9;
//    int maxDay = 6;
//
//    int minYear = 2014;
//    int minMonth = 9;
//    int minDay = 6;
//
//    char oldestName[6];
//    char youngestName[6];
//
//    int totalValid = 0;
//
//    for(int i = 0; i < N; i++) {
//        char name[6];
//        int year = 0;
//        int month = 0;
//        int day = 0;
//        scanf("%s %d/%d/%d", name, &year, &month, &day);
//
//        if(!isValid(year, month, day)) {
//            continue;
//        }
//
//        // Increase total valid
//        totalValid++;
//
//        // Check max
//        if(year > maxYear ||
//                (year == maxYear && month > maxMonth) ||
//                (year == maxYear && month == maxMonth && day > maxDay)) {
//            maxYear = year;
//            maxMonth = month;
//            maxDay = day;
//            strcpy(youngestName, name);
//        }
//
//        if(year < minYear ||
//                (year == minYear && month < minMonth) ||
//                (year == minYear && month == minMonth && day < minDay)) {
//            minYear = year;
//            minMonth = month;
//            minDay = day;
//            strcpy(oldestName, name);
//        }
//    }
//
//    if(totalValid == 0) {
//        printf("%d", totalValid);
//    } else {
//        printf("%d %s %s", totalValid, oldestName, youngestName);
//    }
//    return 0;
//}

struct Person {
    int year;
    int month;
    int day;
    char name[6];
} temp, oldestPerson, youngestPerson, leftMost, rightMost;


int isLessThanLeft(struct Person target, struct Person left) {
    if(target.year != left.year) {
        return target.year < left.year;
    }

    if(target.month != left.month) {
        return target.month < left.month;
    }

    if(target.day != left.day) {
        return target.day < left.day;
    }

    return 0;
}

int isMoreThanRight(struct Person target, struct Person right) {
    if(target.year != right.year) {
        return target.year > right.year;
    }

    if(target.month != right.month) {
        return target.month > right.month;
    }

    if(target.day != right.day) {
        return target.day > right.day;
    }

    return 0;
}

void init() {
    leftMost.year = 1814;
    leftMost.month = 9;
    leftMost.day = 6;

    youngestPerson = leftMost;

    rightMost.year = 2014;
    rightMost.month = 9;
    rightMost.day = 6;

    oldestPerson = rightMost;
}

int main() {
    // Initialize env
    init();
    // Input N
    int N = 0;
    scanf("%d", &N);

    int total = 0;

    for(int i = 0; i < N; i++) {
        scanf("%s %d/%d/%d", temp.name, &temp.year, &temp.month, &temp.day);
        if(isLessThanLeft(temp, leftMost) || isMoreThanRight(temp, rightMost)) {
            continue;
        }

        total++;

        if(isLessThanLeft(temp, oldestPerson)) {
            oldestPerson = temp;
        }

        if(isMoreThanRight(temp, youngestPerson)) {
            youngestPerson = temp;
        }
    }

    if(total == 0) {
        printf("%d", total);
    } else {
        printf("%d %s %s", total, oldestPerson.name, youngestPerson.name);
    }
    return 0;
}
