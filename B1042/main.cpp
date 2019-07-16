#include <iostream>

using namespace std;

// B1042: 字符统计
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805280817135616>

int charSummary[26] = {0};

char toLowerCase(char ch) {
    if(ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }

    return ch;
}

int main() {
    char line[1001];
    cin.getline(line, 1001);

    int maxFreq = 0;
    char freqChar = '\0';

    char* ptr = line;
    while(*ptr != '\0') {
        if(isalpha(*ptr)) {
            char lowercase = toLowerCase(*ptr);
            int lowercaseIndex = lowercase - 'a';
            charSummary[lowercaseIndex] ++;
            if(charSummary[lowercaseIndex] > maxFreq) {
                freqChar = lowercase;
                maxFreq = charSummary[lowercaseIndex];
            } else if(charSummary[lowercaseIndex] == maxFreq && lowercase < freqChar) {
                freqChar = lowercase;
            }
        }
        ptr++;
    }

    cout << freqChar << " " << maxFreq;
    return 0;
}
