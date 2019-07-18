#include <iostream>
#include <algorithm>

using namespace std;

// A1070: Mooncake
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805399578853376>
// Note:
// 1. 这里需要注意库存的单位为 thousand tons，也就意味着，库存不一定是整数。

struct MoonCake {
    double inventory;
    double price;
    double unitPrice;
} moonCakes[1000];

bool cakeCmp(MoonCake& l, MoonCake& r) {
    return l.unitPrice > r.unitPrice;
}

int main() {
    int N = 0;
    double D = 0;
    scanf("%d %lf", &N, &D);

    for(int i = 0; i < N; i++) {
        scanf("%lf", &moonCakes[i].inventory);
    }

    for(int i = 0; i < N; i++) {
        scanf("%lf", &moonCakes[i].price);
        moonCakes[i].unitPrice = moonCakes[i].price / moonCakes[i].inventory;
    }

    // Sort with unit price
    sort(moonCakes, moonCakes + N, cakeCmp);

    double profit = 0;

    for(int i = 0; i < N; i++) {
        MoonCake mc = moonCakes[i];
        if(mc.inventory > D) {
            profit += mc.unitPrice * D;
            break;
        } else {
            profit += mc.price;
            D -= mc.inventory;
        }
    }

    printf("%.2f", profit);
    return 0;
}
