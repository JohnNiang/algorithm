#include <iostream>
#include <algorithm>

using namespace std;

// A1033: To Fill or Not to Fill
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805458722734080>
const double infinite = 999999999;

struct Station {
    double unitPrice;
    double distance;
} stations[501];

bool distanceCmp(Station& l, Station& r) {
    return l.distance < r.distance;
}

int main() {
    double C = 0; // Maxinum capacity of the tank
    double D = 0; // (distance)Hangzhou -> destination
    double A = 0; // Average distance per unit gas
    int N = 0; // Total number of gas stations

    scanf("%lf %lf %lf %d", &C, &D, &A, &N);

    int n = 0;
    for(; n < N; n++) {
        scanf("%lf %lf", &stations[n].unitPrice, &stations[n].distance);
    }

    // This is crucial.
    stations[n].distance = D;
    stations[n].unitPrice = 0;

    sort(stations, stations + N, distanceCmp);

    if(stations[0].distance != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }

    double fullGasDistance = A * C;

    int cur = 0;
    double total = 0;
    double capacity = 0;

    while(cur < N) {
        // Find the first cheaper station than current
        double minPrice = infinite;
        int minPos = -1;
        for(int j = cur + 1; j <= N && stations[j ].distance <= stations[cur].distance + fullGasDistance; j++) {
            if(stations[j].unitPrice < minPrice) {
                minPrice = stations[j].unitPrice;
                minPos = j;

                if(stations[j].unitPrice < stations[cur].unitPrice) {
                    break;
                }
            }
        }

        if(minPos == -1) {
            break;
        }

        double needCap = (stations[minPos].distance - stations[cur].distance) / A;

        if(minPrice < stations[cur].unitPrice) {
            // Add the gas to the cheaper station
            if(capacity < needCap) {
                total += (needCap - capacity) * stations[cur].unitPrice;
                capacity = 0;
            } else {
                capacity -= needCap;
            }
        } else {
            // Fullfill the gas
            total += (C - capacity) * stations[cur].unitPrice;
            capacity = C - needCap;
        }

        // Go to the next station
        cur = minPos;
    }

    if(cur == N) {
        printf("%.2lf", total);
    } else {
        printf("The maximum travel distance = %.2lf", stations[cur].distance + fullGasDistance);
    }

    return 0;
}
