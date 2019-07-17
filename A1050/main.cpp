#include <iostream>
#include <string.h>

using namespace std;

// A1050: String Substraction
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805429018673152>

bool secondChar[128] = {0};

char first_line[10001] = {0};
char second_line[10001] = {0};

int main() {
    // Initialize it
    memset(secondChar, false, sizeof(secondChar));

    cin.getline(first_line, 10001);
    cin.getline(second_line, 10001);

    char* ptr = second_line;
    while(*ptr != '\0') {
        secondChar[*ptr] = true;
        ptr++;
    }

    ptr = first_line;
    while(*ptr != '\0') {
        if(!secondChar[*ptr]) {
            printf("%c", *ptr);
        }
        ptr++;
    }

    return 0;
}
