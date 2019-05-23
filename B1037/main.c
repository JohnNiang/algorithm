#include <stdio.h>
#include <stdlib.h>

// B1037: 在霍格沃茨找零钱
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805284923359232>

struct Concurrency {
    int galleon;
    int sickle;
    int knut;
} predict, actual, diff;

struct Concurrency subConcurrency(struct Concurrency left, struct Concurrency right) {
    struct Concurrency result;
    if(left.knut < right.knut) {
        // Borrow from sickle
        left.sickle--;
        left.knut += 29;
    }

    if(left.sickle < right.sickle) {
        // Borrow from galleon
        left.galleon--;
        left.sickle += 17;
    }

    result.knut = left.knut - right.knut;
    result.sickle = left.sickle - right.sickle;
    result.galleon = left.galleon - right.galleon;
    return result;
}

int main() {
    // Input Predict and Actual concurrencies
    scanf("%d.%d.%d %d.%d.%d",
          &predict.galleon, &predict.sickle, &predict.knut,
          &actual.galleon, &actual.sickle, &actual.knut);

//    printf("Predict: %d.%d.%d\n", predict.galleon, predict.sickle, predict.knut);
//    printf("Actual: %d.%d.%d\n", actual.galleon, actual.sickle, actual.knut);

    struct Concurrency result = subConcurrency(predict, actual);

    if(result.galleon < 0) {
        // Remnent
        struct Concurrency empty = {0, 0, 0};
        result = subConcurrency(empty, result);
    } else {
        // Not enough
        result.galleon *= -1;
    }

    printf("%d.%d.%d", result.galleon, result.sickle, result.knut);

    return 0;
}
