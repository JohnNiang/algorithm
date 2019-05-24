#include <stdio.h>
#include <stdlib.h>

// A1058: A+B in Hogwarts
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805416519647232>

struct Concurrency {
    int galleon;
    int sickle;
    int knut;
} a, b;

struct Concurrency add(struct Concurrency a, struct Concurrency b) {
    struct Concurrency result;
    int carry = 0;

    int knut = a.knut + b.knut + carry;
    result.knut = knut % 29;
    carry = knut / 29;

    int sickle = a.sickle + b.sickle + carry;
    result.sickle =  sickle % 17;
    carry = sickle / 17;

    int galleon = a.galleon + b.galleon + carry;
    result.galleon = galleon;

    return result;
};

int main() {
    // Input a and b
    scanf("%d.%d.%d %d.%d.%d",
          &a.galleon, &a.sickle, &a.knut,
          &b.galleon, &b.sickle, &b.knut);

    struct Concurrency result = add(a, b);
    printf("%d.%d.%d", result.galleon, result.sickle, result.knut);
    return 0;
}
