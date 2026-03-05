#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main ()
{
    int n;
    cin >> n;

    vector <int> a(n);

    for (auto & c : a) { cin >> c; }

    vector <vector <int>> frequency(n + 1);
    for (int i = 0; i < n; i++) { frequency[a[i]].push_back(i); }

    vector <int> num_distinct(n);
    set <int> distinct_vals;
    for (int i = 0; i < n; i++)
    {
        num_distinct[i] = distinct_vals.size();
        distinct_vals.insert(a[i]);
    }

    ll ans = 0;
    for (int num = 1; num <= n; num++)
    {
        if (frequency[num].size() >= 2)
        {
            int second_last_index = frequency[num][frequency[num].size() - 2];
            ans += num_distinct[second_last_index];
            if (frequency[num].size() >= 3) { ans--; }
        }
    }

    cout << ans << "\n";
    return 0;
}