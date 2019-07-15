#include <iostream>
#include <map>
using namespace std;

// A1084: Broken Keyboard
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805382902300672>

map<char, bool> typedMap;

bool table[255];

char toUppercase(char ch) {
    if(ch >= 97 && ch <= 122) {
        return ch - 32;
    }

    return ch;
}

int main() {
    char original[81];
    char typed[81];
    scanf("%s %s", original, typed);

    char* ptr = typed;
    while(*ptr != '\0') {
        typedMap[*ptr] = true;
        ptr++;
    }

    ptr = original;
    while(*ptr != '\0') {
        if(typedMap.count(*ptr) == 0) {
            char upperKey = toUppercase(*ptr);
            if(!table[upperKey]) {
                table[upperKey] = true;
                cout << upperKey;
            }
        }
        ptr++;
    }

    return 0;
}
