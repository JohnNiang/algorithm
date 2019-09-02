#include <iostream>

using namespace std;

// B1003: 我要通过！
// <https://pintia.cn/problem-sets/994805260223102976/problems/994805323154440192>

// Notes:
// 题目的逻辑虽然简单，但是想要分析出来却很不容易的。
// 最重要的就是找出规律：z - (y - 1) * x == x 就算是正确的答案。

int main()
{
    int N = 0;
    cin >> N;
    getchar();
    while(N--)
    {
        string pat;
        getline(cin, pat);
        // Find total a before p, between p and t, after t.
        int p_num = 0;
        int t_num = 0;
        int other = 0;
        int p_locale = -1;
        int t_locale = -1;

        for(int i= 0; i < pat.length(); i++)
        {
            char ch = pat.at(i);
            if(ch == 'P')
            {
                p_num ++;
                p_locale = i;
            }
            else if(ch == 'T')
            {
                t_num ++;
                t_locale = i;
            }
            else if(ch != 'A')
            {
                other ++;
            }
        }

        if(p_num != 1 || t_num != 1 || other > 0 || (t_locale - p_locale) <= 1)
        {
            cout << "NO" << endl;
            continue;
        }

        int x = p_locale;
        int y = t_locale - p_locale - 1;
        int z = pat.length() - t_locale - 1;

        if(z - (y - 1) * x == x)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
