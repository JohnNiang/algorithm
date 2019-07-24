#include <iostream>
#include <algorithm>

using namespace std;

// A1038: Recover the Smallest Number
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805449625288704>

string numbers[10000];

// Important!!!
bool numberCmp(string l, string r) {
    return l + r < r + l;
}

int main() {
    int N = 0;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    sort(numbers, numbers + N, numberCmp);

    string result;

    for(int i = 0; i < N; i++) {
        result += numbers[i];
    }

    // Erase the 0
    while(result.size() != 0 && result[0] == '0') {
        result.erase(result.begin());
    }

    if(result.size() == 0) {
        cout << 0;
    } else {
        cout << result;
    }

    return 0;
}
