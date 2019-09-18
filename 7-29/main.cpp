#include <iostream>
#include <string.h>

using namespace std;

// 7-29: 删除字符串中的子串
// <https://pintia.cn/problem-sets/14/problems/809>

int main() {
    char s1[81];
    char s2[81];


    cin.getline(s1, 81);
    cin.getline(s2, 81);

    int len = strlen(s2);

    for(char* p; p = strstr(s1, s2);) {
        for(; *p = *(p + len); p++);
        *p = 0;
    }

    cout << s1 << endl;
    return 0;
}
