#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// A1055: The World's Richest
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805421066272768>

struct People {
    char name[9];
    int age;
    int netWorth;
} people[100010], temp[100010];

int ageStat[201] = {0};

bool resultCompare(People& left, People& right) {
    if(left.netWorth != right.netWorth) {
        return left.netWorth > right.netWorth;
    }

    if(left.age != right.age) {
        return left.age < right.age;
    }

    return strcmp(left.name, right.name) < 0;
}

int main() {
    // Total number of people
    int N = 0;
    // Number of queries
    int K = 0;

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> people[i].name >> people[i].age >> people[i].netWorth;
    }

    // Sort with age
    sort(people, people + N, resultCompare);

    int tempNum = 0;
    for(int i = 0; i < N; i++) {
        if(ageStat[people[i].age] < 100) {
            ageStat[people[i].age]++;
            temp[tempNum++] = people[i];
        }
    }

    int maxOutput = 0;
    int ageMin = 0;
    int ageMax = 0;
    for(int i = 0; i < K; i++) {
        cin >> maxOutput >> ageMin >> ageMax;

        cout << "Case #" << i + 1 << ":" << endl;

        int outputNum = 0;
        for(int j = 0; j < tempNum && outputNum < maxOutput; j++) {
            if(temp[j].age >= ageMin && temp[j].age <= ageMax) {
                cout << people[j].name << " " << people[j].age << " " << people[j].netWorth << endl;
                outputNum++;
            }
        }

        if(outputNum == 0) {
            cout << "None" << endl;
        }
    }

    return 0;
}
