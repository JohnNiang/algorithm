#include <iostream>

using namespace std;

// B1023: 组个最小数
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805298269634560>


int main() {
    int digitStat[10];

    for(int i = 0; i < 10; i++) {
        scanf("%d", &digitStat[i]);
    }

    // Print first digit
    for(int i = 1; i < 10; i++) {
        if(digitStat[i] > 0) {
            printf("%d", i);
            digitStat[i]--;
            break;
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < digitStat[i]; j++) {
            printf("%d", i);
        }
    }

//    for(int i = 0; i < 10; i++) {
//        int digit = 0;
//        scanf("%d", &digit);
//        for(int j = 0; j < digit; j++) {
//            digitStat[i]++;
//        }
//    }
//
//    int i = 0;
//    bool printFirst = true;
//    while(i != 10) {
//        if(printFirst) {
//            i = 1;
//            printFirst = false;
//        } else {
//            i = 0;
//        }
//
//        for(; i < 10; i++) {
//            if(digitStat[i]) {
//                printf("%d", i);
//                digitStat[i]--;
//                break;
//            }
//        }
//    }

    return 0;
}
