#include <iostream>
#include <algorithm>

using namespace std;

// A1069: The Black Hole of Numbers
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805400954585088>

bool intDecCompare(int left, int right)
{
    return left > right;
}

void toArray(int number, int* digits)
{
    for(int i = 0; i < 4; i++)
    {
        digits[i] = number % 10;
        number /= 10;
    }
}

int toInteger(int* digits)
{
    int result = 0;
    for(int i = 0; i < 4; i++)
    {
        result = result * 10 + digits[i];
    }
    return result;
}

int main()
{
    int number = 0;
    cin >> number;

    if(number % 1111 == 0)
    {
        cout << number << " - " << number << " = 0000" << endl;
        return 0;
    }

    do
    {
        int digits[4] = {0};
        toArray(number, digits);
        // Convert to decreasing order
        sort(digits, digits + 4, intDecCompare);
        int max = toInteger(digits);
        sort(digits, digits + 4);
        int min = toInteger(digits);

        number = max - min;

        printf("%04d - %04d = %04d\n", max, min, number);

        if(number == 0)
        {
            break;
        }
    }
    while(number != 6174);

    return 0;
}
