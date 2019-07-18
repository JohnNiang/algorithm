#include <iostream>

using namespace std;

// A1048: Find Coins
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805432256675840>

// Note:
// 1. 这里有一个很巧妙的点，就是使用一个数组统计 coin 出现的次数；
// 2. 且通过判断两个下标对应的次数是否存在来表示能够满足条件；
// 3. 这里的 coinStat 的长度一定要至少得等于 M 的值，这样在循环的时候不至于溢出。

int coinStat[1001];

int main() {
    int N = 0;
    int M = 0;

    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++) {
        int coin = 0;
        scanf("%d", &coin);
        coinStat[coin]++;
    }

    for(int i = 0; i < M; i++) {
        if(coinStat[i] && coinStat[M - i]) {
            if(i == M - i && coinStat[i] <= 1) {
                continue;
            }

            printf("%d %d", i, M - i);
            return 0;
        }
    }

    printf("No Solution");
    return 0;
}
