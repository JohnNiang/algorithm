#include <iostream>
#include <string.h>

using namespace std;

// B1033: 旧键盘打字
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805288530460672>

// Note:
// 1. 注意读取第一行的时候有可能是空行。所以需要用到 gets 或者 getline 函数；
// 2. 注意上档键。

bool brokenKeys[256];
char line[100000];

char isUpperCase(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

char toUpperCase(char ch) {
    if(ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 'A';
    }

    return ch;
}

int main() {
    memset(brokenKeys, false, sizeof(brokenKeys));
    cin.getline(line, 100000);
    char* ptr = line;
    bool shiftBroken = false;
    while(*ptr != '\0') {
        if(*ptr == '+') {
            shiftBroken = true;
        }
        brokenKeys[*ptr] = true;
        ptr++;
    }

    cin.getline(line, 100000);

    ptr = line;
    while(*ptr != '\0') {
        if(isUpperCase(*ptr)) {
            if(!shiftBroken && !brokenKeys[*ptr]) {
                cout << *ptr;
            }
        } else if(!brokenKeys[toUpperCase(*ptr)]) {
            cout << *ptr;
        }
        ptr++;
    }
    return 0;
}
