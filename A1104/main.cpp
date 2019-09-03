#include <iostream>

using namespace std;

// A1104: Sum of Number Segments
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805363914686464>

int main()
{
    int N = 0;
    cin >> N;
    double total = 0.0;
    for(int i = 1; i <= N; i++)
    {
        double n = 0.0;
        cin >> n;
        total += n * (i * (N - i + 1));
    }

    printf("%.2f", total);
    return 0;
}
