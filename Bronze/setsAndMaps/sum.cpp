#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, x;
    cin >> n >> x;

    map <long long, pair<int, long long>> values;
    int esq = 0, dir = 0;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;

        long long b = x - a;
        if (values.count(b))
        {
            dir = i + 1;
            esq = values[b].first;
            break;
        }

        values[a] = {i + 1, x - a};
    }

    if(dir)
    {
        cout << esq << " " << dir;
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}