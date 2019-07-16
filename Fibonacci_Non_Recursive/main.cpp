#include <iostream>
#include <stack>

using namespace std;

// 关于 Fibonacci 数列的非递归算法的实现。

struct Fibonacci {
    int n;
    int result;
};

/**
 * Implemente by stack.
 */
int fib_in_stack(int n) {
    stack<Fibonacci> s;
    for(int i = n; i > 2; i--) {
        Fibonacci f;
        f.n = i;
        s.push(f);
    }

    int prev = 0;
    int next = 1;

    while(!s.empty()) {
        Fibonacci f = s.top();
        f.result = prev + next;
        prev = next;
        next = f.result;
        s.pop();
    }

    if(n == 1) {
        return prev;
    }

    return next;
}

/**
 * Implemente by loop.
 */
int fib_in_none(int n) {
    int prev = 0;
    int next = 1;
    for(int i = 0; i < n - 2; i++) {
        int sum = prev + next;
        prev = next;
        next = sum;
    }

    if(n == 1) {
        return prev;
    }

    return next;
}

int main() {
    int n = 30;
    for(int i = 1; i <= n; i++)
        cout << fib_in_stack(i) << endl;

    for(int i = 1; i <= n; i++) {
        cout << fib_in_none(i) << endl;
    }
    return 0;
}
