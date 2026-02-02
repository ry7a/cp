#include <bits/stdc++.h>
using namespace std;

const int interval = 1001;

int main ()
{
    int numberOflifeguards;
    freopen("lifeguards.in", "r", stdin);
    cin >> numberOflifeguards;
    
    vector <pair<int, int>> lifeguards (numberOflifeguards); 
    for (auto & lifeguard : lifeguards) { cin >> lifeguard.first >> lifeguard.second; }

    int ans = 0;
    for (auto lifeguard : lifeguards)
    {
        int timeGuarded = 0;
        vector <bool> path (interval, false);
        for (auto p : lifeguards)
        {
            if (p == lifeguard) { continue; }
            for (int i = p.first + 1; i <= p.second; i++) { path[i] = true; }
        }
        
        for (auto p : path) { timeGuarded += p; }

        ans = max(ans, timeGuarded);
    }

    freopen("lifeguards.out", "w", stdout); 
    cout << ans << endl;

    return 0;
}