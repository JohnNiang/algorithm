#include <iostream>
#include <vector>

using namespace std;

// A1103: Integer Factorization
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805364711604224>

int maxFacSum = -1;
vector<int> v, ans, tempAns;

int pow(int num, int index) {
    int result = 1;
    for(int i = 0; i < index; i++) {
        result *= num;
    }
    return result;
}

void init(int n, int index) {
    int temp = 0;
    int i = 1;
    while(temp <= n) {
        v.push_back(temp);
        temp = pow(i++, index);
    }
}

void dfs(int i, int tempSum, int tempK, int facSum, int n, int k, int index) {
    if(tempK == k) {
        if(tempSum == n && facSum > maxFacSum) {
            ans = tempAns;
            maxFacSum = facSum;
        }
        return;
    }

    while(i >= 1) {
        if(tempSum + v[i] <= n) {
            tempAns[tempK] = i;
            dfs(i, tempSum + v[i], tempK + 1, facSum + i, n, k, index);
        }
        i--;
    }
}

int main() {
    int n = 0;
    int k = 0;
    int p = 0;
    cin >> n >> k >> p;
    init(n, p);
    tempAns.resize(k);
    dfs(v.size() - 1, 0, 0, 0, n, k, p);
    if(maxFacSum == -1) {
        cout << "Impossible";
        return 0;
    }

    cout << n << " = ";
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) {
            cout << " + ";
        }
        cout << ans[i] << "^" << p;
    }
    return 0;
}
