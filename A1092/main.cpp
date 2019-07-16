#include <iostream>

using namespace std;

// A1092: To Buy or Not to Buy
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805374509498368>

// Note:
// 可以考虑采用消减的方式来统计缺失的球，这样就能够省下一 256 的空间和减少最后的 [48 ,122] 的循环。

int shopBeadSummary[256] = {0};
int evaBeadSummary[256] = {0};

char beads[1001];
int main() {
    // Handle shop bead
    cin >> beads;
    char* ptr = beads;
    while(*ptr != '\0') {
        shopBeadSummary[*ptr]++;
        ptr++;
    }

    // Handle eva bead
    cin >> beads;
    ptr = beads;
    while(*ptr != '\0') {
        evaBeadSummary[*ptr]++;
        ptr++;
    }

    int missing = 0;
    int extra = 0;
    for(int i = 48; i < 123; i++) {
        int shopBeadTotal = shopBeadSummary[i];
        int evaBeadTotal = evaBeadSummary[i];
        if(shopBeadTotal < evaBeadTotal) {
            missing += (evaBeadTotal - shopBeadTotal);
        } else {
            extra += (shopBeadTotal - evaBeadTotal);
        }
    }

    if(missing > 0) {
        cout << "No " << missing;
    } else {
        cout << "Yes " << extra;
    }
    return 0;
}
