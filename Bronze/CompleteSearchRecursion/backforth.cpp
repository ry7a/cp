#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set <int> possibles;
void solve (ll trips_left, const vector<ll> &buckets_here, const vector <ll> &buckets_there,
            ll tank_here, ll tank_there)
{
    if (trips_left == 0) { possibles.insert(tank_here); }
    else
    {
        for (int taken_idx = 0; taken_idx < buckets_here.size(); taken_idx++)
        {
            ll taken_bucket = buckets_here[taken_idx];
            vector <ll> new_buckets_here;
            for (int i = 0; i < buckets_here.size(); i++)
            {
                if (i != taken_idx) { new_buckets_here.push_back(buckets_here[i]); }
            }

            vector <ll> new_buckets_there (buckets_there);
            new_buckets_there.push_back(taken_bucket);

            ll new_tank_here = tank_here - taken_bucket;
            ll new_tank_there = tank_there + taken_bucket;
            solve (trips_left-1, new_buckets_there, new_buckets_here, new_tank_there, new_tank_here);
        }
    }
}

int main ()
{
    assert(freopen("backforth.in", "r", stdin) != nullptr);
    assert(freopen("backforth.out", "w", stdout) != nullptr);

    vector <ll> first_barn(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> first_barn[i];
    }

    vector <ll> second_barn(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> second_barn[i];
    }

    solve(4, first_barn, second_barn, 1000, 1000);
    cout << possibles.size() << endl;
    return 0;
}