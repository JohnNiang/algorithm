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

int p_in_none(int x, int n) {
    int prev = 1;
    int next = 2 * x;
    for(int i = 2; i <= n; i++) {
        int temp = 2 * x * next - 2 * (i - 1) * prev;
        prev = next;
        next = temp;
    }

    if(n == 0) {
        return prev;
    }

    return next;
}

struct stack {
    int n;
    double val;
} st[1000];

double p_in_stack(int x, int n) {
    int top = -1;
    double fv1 = 1;
    double fv2 = 2 * x;
    for(int i = n; i >= 2; i--) {
        st[++top].n = i;
    }

    while(top >= 0) {
        st[top].val = 2 * x * fv2 - 2 * (st[top].n - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top].val;
        top--;
    }

    if(n == 0) {
        return fv1;
    }

    return fv2;
}

int main() {
    int n = 10;
    for(int i = 1; i <= n; i++)
        cout << fib_in_stack(i) << endl;

    for(int i = 1; i <= n; i++) {
        cout << fib_in_none(i) << endl;
    }

    cout << "P in none: " << endl;
    for(int i = 0; i < n; i++) {
        cout << p_in_none(0, i) << endl;
    }

    cout << "P in stack" << endl;
    for(int i = 0; i < n; i++) {
        cout << p_in_stack(0, i) << endl;
    }

    return 0;
}
