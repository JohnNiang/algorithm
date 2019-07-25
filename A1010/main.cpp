#include <iostream>

using namespace std;

// A1010: Radix
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805507225665536>

long long digitMap[128] = {0};

const long long LLONG_MAX = (1LL << 63) - 1;

void initMap() {
    // Store the digits
    for(char d = '0'; d <= '9'; d++) {
        digitMap[d - 0] = d - '0';
    }

    // Store the characters
    for(char c = 'a'; c <= 'z'; c++) {
        digitMap[c - 0] = c - 'a' + 10;
    }
}

long long convertToDigit(string number, long long radix, long long maximum) {
    long long digitalNumber = 0;
    for(char& c : number) {
        digitalNumber = digitalNumber * radix + digitMap[c - 0];
        if(digitalNumber < 0 || digitalNumber > maximum) {
            return -1;
        }
    }

    return digitalNumber;
}

int compare(string number, long long radix, long long digitalNumber) {
    long long convertedValue = convertToDigit(number, radix, digitalNumber);

    if(convertedValue < 0) {
        return 1;
    }

    if(convertedValue > digitalNumber) {
        return 1;
    } else if(convertedValue == digitalNumber) {
        return 0;
    } else {
        return -1;
    }
}

int binarySearch(string number, long long left, long long right, long long standard) {
    while(left <= right) {
        long long middle = (left + right) / 2;
        int result = compare(number, middle, standard);
        if(result == 0) {
            return middle;
        } else if(result < 0) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int findLargestDigit(string n) {
    int largestDigit = -1;
    for(char& c : n) {
        if(digitMap[c - 0] > largestDigit) {
            largestDigit = digitMap[c - 0];
        }
    }

    return largestDigit + 1;
}


int main() {
    // Init the map
    initMap();

    // Handle inputing
    string n1;
    string n2;
    int tag = 0;
    long long radix = 0;
    cin >> n1 >> n2 >> tag >> radix;

    if(tag == 2) {
        n1.swap(n2);
    }

    long long maximum = convertToDigit(n1, radix, LLONG_MAX);
    long long left = findLargestDigit(n2);
    long long right = max(maximum, left) + 1;

    long long result = binarySearch(n2, left, right, maximum);
    if(result < 0) {
        cout << "Impossible" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
