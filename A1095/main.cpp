#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

// A1095: Cars on Campus
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805371602845696>

struct Record {
    char plateNumber[8];
    int time; // unit: seconds
    bool status; // true: in; false: out
} records[10000], valids[10000];

map<string, int> parkingTimeMap;

bool timeCmp(Record& l, Record& r) {
    return l.time < r.time;
}

bool recordCmp(Record& l, Record& r) {
    int numberCmp = strcmp(l.plateNumber, r.plateNumber);
    if(numberCmp != 0) {
        return numberCmp < 0;
    }

    return timeCmp(l, r);
}

int timeToInt(int hour, int minute, int second) {
    return hour * 3600 + minute * 60 + second;
}

void print(Record* records, int n) {
    for(int i = 0; i < n; i++) {
        printf("%s %d %d\n",  records[i].plateNumber, records[i].time, records[i].status);
    }
}

int main() {
    int N = 0;
    int K = 0;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) {
        char status[4] = {0};
        int hour = 0;
        int minute = 0;
        int second = 0;

        scanf("%s %d:%d:%d %s", records[i].plateNumber, &hour, &minute, &second, status);
        records[i].time = timeToInt(hour, minute, second);
        if(strcmp(status, "in") == 0) {
            records[i].status = true;
        }
    }

    // Sort the records
    sort(records, records + N, recordCmp);

    int validNum = 0;
    int maxParkingTime = 0;
    for(int i = 0; i < N - 1; i++) {
        if(strcmp(records[i].plateNumber, records[i + 1].plateNumber) == 0 &&
                records[i].status &&
                !records[i + 1].status) {
            // This is valid
            valids[validNum++] = records[i];
            valids[validNum++] = records[i + 1];
            // Calculate the parking time
            int parkingTime = records[i + 1].time - records[i].time;

            if(parkingTimeMap.count(records[i].plateNumber) == 0) {
                parkingTimeMap[records[i].plateNumber] = 0;
            }

            parkingTimeMap[records[i].plateNumber] += parkingTime;
            maxParkingTime = max(maxParkingTime, parkingTimeMap[records[i].plateNumber]);
        }
    }


    // Sort the valid records
    sort(valids, valids + validNum, timeCmp);

//    print(valids, validNum);

    int current = 0;
    int parkingNum = 0;

    for(int i = 0; i < K; i++) {
        int hour;
        int minute;
        int second;
        scanf("%d:%d:%d", &hour, &minute, &second);

        int queryTime = timeToInt(hour, minute, second);

        while(current < validNum && valids[current].time <= queryTime) {
            if(valids[current].status) {
                parkingNum ++;
            } else {
                parkingNum --;
            }
            current++;
        }

//        cout << "Querying: " << queryTime << endl;
        cout << parkingNum << endl;
    }

    for(map<string, int>::iterator it = parkingTimeMap.begin(); it != parkingTimeMap.end(); it++) {
        if(it->second == maxParkingTime) {
            cout << it->first << " ";
        }
    }

    printf("%02d:%02d:%02d", maxParkingTime / 3600, maxParkingTime % 3600 / 60, maxParkingTime % 60);

    return 0;
}
