#include <iostream>
#include <queue>

using namespace std;

// A1056: Mice And Rice
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805419468242944>

struct Mouse
{
    int weight;
    int rank;
} mice[1000];

int main()
{
    int Np = 0;
    int Ng = 0;
    cin >> Np >> Ng;

    for(int i = 0; i < Np; i++)
    {
        cin >> mice[i].weight;
    }

    queue<int> q;

    for(int i = 0; i < Np; i++)
    {
        int order = 0;
        cin >> order;
        q.push(order);
    }

    int total = Np;
    while(q.size() != 1)
    {
        int groups = total / Ng;
        if(total % Ng != 0)
        {
            groups ++;
        }

        for(int i = 0; i < groups; i++)
        {
            // One group
            int k = q.front();

            // Find the winner
            for(int j = 0; j < Ng; j++)
            {
                if(i * Ng + j >= total)
                {
                    break;
                }

                int current = q.front();
                if(mice[current].weight > mice[k].weight)
                {
                    k = current;
                }
                mice[current].rank = groups + 1;
                q.pop();
            }

            // Push group winner
            q.push(k);
        }

        total = groups;
    }

    mice[q.front()].rank = 1;

    for(int i = 0; i < Np; i++)
    {
        if(i != 0)
        {
            cout << " ";
        }
        cout << mice[i].rank;
    }

    return 0;
}
