#include <iostream>
#include <stack>

using namespace std;

// A1051: Pop Sequence
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805427332562944>

int main() {
    int M = 0;
    int N = 0;
    int K = 0;
    cin >> M >> N >> K;

    int numbers[1000];

    for(int k = 0; k < K; k++) {
        for(int n = 0; n < N; n++) {
            cin >> numbers[n];
        }

        int n = N;

        stack<int> s;
        bool exceed = false;
        for(int i = N - 1; i >= 0; i--) {
            if(s.size() == M) {
                exceed = true;
                break;
            }

            s.push(numbers[i]);

            while(!s.empty() && s.top() == n) {
                s.pop();
                n--;
            }
        }

        if(!exceed && s.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
