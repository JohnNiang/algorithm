#include <iostream>

using namespace std;

// B1043: 输出PATest
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805280074743808>

char line[10001];
int patestSummary[6] = {0};
char patestMap[6] = {'P', 'A', 'T', 'e', 's', 't'};

int main() {
    cin >> line;

    char* ptr = line;
    while(*ptr != '\0') {
        for(int i = 0; i < 6; i++) {
            if(patestMap[i] == *ptr) {
                patestSummary[i] ++;
            }
        }
        ptr++;
    }

    bool isEmpty = false;
    while(!isEmpty) {
        isEmpty = true;
        for(int i = 0; i < 6; i++) {
            if(patestSummary[i] > 0) {
                cout << patestMap[i];
                patestSummary[i]--;
            }

            if(patestSummary[i] > 0) {
                isEmpty = false;
            }
        }
    }
    return 0;
}
