#include <iostream>

using namespace std;

// A1041: Be Unique
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805444361437184>

int numberStat[10001] = {0};
int numberContainer[100001] = {0};
int main() {
    int N = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int number = 0;
        scanf("%d", &number);
        numberStat[number]++;
        numberContainer[i] = number;
    }


    int winNumber = 0;

    for(int i = 0; i < N; i++) {
        if(numberStat[numberContainer[i]] == 1) {
            winNumber = numberContainer[i];
            break;
        }
    }

    if(winNumber != 0) {
        printf("%d", winNumber);
    } else {
        printf("None");
    }
    return 0;
}
