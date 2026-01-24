#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define MAXT 1010
vector <int> t(MAXT);

int main()
{
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int N;
    cin >> N;

    for (int c = 0; c < N; c++)
    {
        int start, end, amt;
        cin >> start >> end >> amt;
        t[start] += amt;
        t[end] -= amt;
    }

    int curr_bucket = 0;
    int max_bucket = 0;

    for (int i = 0; i < MAXT; i++)
    {
        curr_bucket += t[i];
        max_bucket = max(curr_bucket, max_bucket);
    }

    cout << max_bucket << "\n";

    return 0;
}