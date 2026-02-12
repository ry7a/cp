#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main ()
{
    int length_base;
    cin >> length_base;

    vector<ll> histogram(length_base);
    for (auto &square : histogram) cin >> square;

    ll ans = 0;

    for (int i = 0; i < length_base; i++)
    {
        ll minHeight = INT64_MAX;

        for (int j = i; j < length_base; j++)
        {
            minHeight = min(minHeight, histogram[j]);
            ll width = j - i + 1;

            if (minHeight >= width)
                ans = max(ans, width);
            else
                break;
        }
    }

    cout << ans << endl;
    return 0;
}
