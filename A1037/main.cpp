#include <iostream>
#include <algorithm>

using namespace std;

// A1037: Magic Coupon
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805451374313472>

int coupons[200000];
int products[200000];

int main() {
    int Nc = 0;
    int Np = 0;
    scanf("%d", &Nc);

    for(int i = 0; i < Nc; i++) {
        scanf("%d", &coupons[i]);
    }

    scanf("%d", &Np);
    for(int i = 0; i < Np; i++) {
        scanf("%d", &products[i]);
    }

    // Sort this collections by natural
    sort(coupons, coupons + Nc);
    sort(products, products + Np);

    int result = 0;
    int i = 0;
    int j = 0;

    // Add from head
    while(i < Nc && i < Np && coupons[i] < 0 && products[i] < 0) {
        result += coupons[i] * products[i];
        i++;
    }

    // Add from the tail
    i = Nc - 1;
    j = Np - 1;
    while(i >= 0 && j >= 0 && coupons[i] > 0 && products[j] > 0) {
        result += coupons[i--] * products[j--];
    }

    printf("%d", result);
    return 0;
}
