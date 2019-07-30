#include <iostream>
#include <algorithm>

using namespace std;

// A1085: Perfect Sequence
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805381845336064>

// Solution 1:

//int numbers[100000];
//
//int binarySearch(int i, long long max, int n) {
//    if(numbers[n - 1] <= max) {
//        return n;
//    }
//    int left = i;
//    int right = n - 1;
//    while(left < right) {
//        int middle = (right + left) / 2;
//        if(numbers[middle] <= max) {
//            left = middle + 1;
//        } else {
//            right = middle;
//        }
//    }
//
//    return right;
//}
//int main() {
//    int N = 0;
//    int p = 0;
//    scanf("%d %d", &N, &p);
//
//    for(int i = 0; i < N; i++) {
//        scanf("%d", &numbers[i]);
//    }
//
//    sort(numbers, numbers + N);
//
//    int maximum = 0;
//    for(int i = 0; i < N; i++) {
//        int j = binarySearch(i + 1, (long long)numbers[i] * p, N);
//        maximum = max(j - i, maximum);
//    }
//
//    printf("%d", maximum);
//    return 0;
//}

// Solution 2:

int numbers[100000];

int main() {
    int N = 0;
    int p = 0;

    scanf("%d %d", &N, &p);

    for(int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    sort(numbers, numbers + N);

    int i = 0;
    int j = 0;
    int count = 0;
    while(i < N && j < N) {
        // 这里可能溢出
        while(j < N && numbers[j] <= (long long)numbers[i] * p) {
            count = max(count, j - i + 1);
            j++;
        }
        i++;
    }

    printf("%d", count);

    return 0;
}
