#include <bits/stdc++.h>
using namespace std;

template <typename T> set <T> intersection (const set<T> s1, const set<T> s2)
{
    set <T> ret;
    for (auto c : s1)
    {
        if (s2.count(c)) { ret.insert(c); }
    }

    return ret;
}

template <typename T> set <T> union_set (const set <T> s1, const set <T> s2)
{
    set <T> uni;
    for (auto c : s1)
    {
        uni.insert(c);
    }

    for (auto c : s2)
    {
        uni.insert(c);
    }

    return uni;
}

int main ()
{
    freopen("badmilk.in", "r", stdin);
    int N, M, D, S;
    cin >> N >> M >> D >> S;

    vector <set<int>> milks (M+1);
    vector <map <int, set<int>>> time (101);
    while (D--)
    {
        int person, milk, t;
        cin >> person >> milk >> t;
        milks[milk].insert(person);

        if (!time[t].count(person)) { time[t].insert({person, {milk}}); }
        else { time[t][person].insert(milk); }
    }

    for (int t = 1; t < 100; t++)
    { 
        for (auto c : time[t]) 
        { 
            if (time[t+1].count(c.first)) 
            { 
                set <int> temporary = union_set(time[t+1][c.first], time[t][c.first]);
                time[t+1][c.first] = temporary;
            }
            else { time[t+1].insert(c); }
        }
    }

    set<int> possibleMilks;
    for (int i = 1; i <= M; i++) possibleMilks.insert(i);
    int S0 = S;
    while (S--)
    {
        int sickPerson, sickTime;
        cin >> sickPerson >> sickTime;

        set<int> temporary = intersection(possibleMilks, time[sickTime-1][sickPerson]);
        possibleMilks = temporary;
    }

    int ans = 0;
    for (auto m : possibleMilks)
    {
        ans = max(ans, (int) milks[m].size());
    }

    freopen("badmilk.out", "w", stdout);
    cout << ans << endl;
    
    return 0;
}