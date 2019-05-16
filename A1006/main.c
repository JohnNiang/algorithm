#include <stdio.h>
#include <stdlib.h>

// A1006: Sign In and Sign Out
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805516654460928>

struct Time {
    int hour;
    int minute;
    int second;
};

struct Person {
    char idNumber[16];
    struct Time signInTime;
    struct Time signOutTime;
} temp, firstSignIn, lastSignOut;

int moreThan(struct Time test, struct Time time) {
    if(test.hour != time.hour) {
        return test.hour > time.hour;
    }

    if(test.minute != time.minute) {
        return test.minute > time.minute;
    }

    if(test.second != time.second) {
        return test.second > time.second;
    }

    return 0;
}

int main() {
    // Input M
    int M = 0;
    scanf("%d", &M);

    for(int i = 0; i < M; i++) {
        // Input one case
        scanf("%s %d:%d:%d %d:%d:%d", temp.idNumber,
              &(temp.signInTime.hour), &(temp.signInTime.minute), &(temp.signInTime.second),
              &(temp.signOutTime.hour), &(temp.signOutTime.minute), &(temp.signOutTime.second));
        if(i == 0) {
            firstSignIn = temp;
            lastSignOut = temp;
            continue;
        }

        if(!moreThan(temp.signInTime, firstSignIn.signInTime)) {
            firstSignIn = temp;
        }

        if(moreThan(temp.signOutTime, lastSignOut.signOutTime)) {
            lastSignOut = temp;
        }
    }

    printf("%s %s", firstSignIn.idNumber, lastSignOut.idNumber);
    return 0;
}
