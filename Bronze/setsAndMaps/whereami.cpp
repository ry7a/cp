#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll BASE = 131;
const ll MOD = 1e9 + 7;

int main ()
{
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int N;
    string s;
    cin >> N >> s;

    vector <ll> pref(N+1, 0);
    vector <ll> power(N+1, 1);

    for (int i = 1; i <= N; i++)
    {
        pref[i] = (pref[i-1]*BASE + s[i - 1]) % MOD;
        power[i] = (power[i - 1]*BASE) % MOD;
    }

    auto getHash = [&](int l, int r)
    {
        ll hash = (pref[r+1] - pref[l]*power[r-l+1]) % MOD;
        if (hash < 0) hash += MOD;
        return hash;
    };

    auto valid = [&](int K)
    {
        unordered_set<ll> seen;
        for (int i = 0; i + K - 1 < N; i++)
        {
            ll h = getHash(i, i+K-1);
            if (seen.count(h)) return false;
            seen.insert(h);
        }
        return true;
    };

    int l = 1, r = N, ans = N;
    
    while (l <= r)
    {
        int mid = (l + r)/2;
        if (valid(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else { l = mid + 1;}
    }

    cout << ans << "\n";

    return 0;
}