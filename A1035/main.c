#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A1035: Password
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805454989803520>

struct Team {
    char username[11];
    char password[11];
} tempTeam, modifiedTeams[1000];


bool modify(char *password) {
    bool isModified = false;
    char *ptr = password;

    while(*ptr != '\0') {
        if(*ptr == '1') {
            *ptr = '@';
            isModified = true;
        }

        if(*ptr == '0') {
            *ptr = '%';
            isModified = true;
        }

        if(*ptr == 'l') {
            *ptr = 'L';
            isModified = true;
        }

        if(*ptr == 'O') {
            *ptr = 'o';
            isModified = true;
        }

        ptr++;
    }

    return isModified;
}

int main() {
    int N = 0;
    scanf("%d", &N);

    int modified = 0;

    for(int i = 0; i < N; i++) {
        scanf("%s %s", tempTeam.username, tempTeam.password);
        bool isModified = modify(tempTeam.password);
        if(isModified) {
            modifiedTeams[modified++] = tempTeam;
        }
    }

    if(modified == 0) {
        // Notice here
        if(N == 1) {
            printf("There is 1 account and no account is modified");
        } else {
            printf("There are %d accounts and no account is modified", N);
        }
    } else {
        printf("%d\n", modified);
        for(int i = 0; i < modified; i++) {
            printf("%s %s\n", modifiedTeams[i].username, modifiedTeams[i].password);
        }
    }

    return 0;
}
