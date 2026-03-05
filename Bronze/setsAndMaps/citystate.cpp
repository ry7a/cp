#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map <string, string> city_states;
map <string, string> states_city;

int main ()
{
    freopen("citystate.in", "r", stdin);
    int num_cities;
    cin >> num_cities;

    map <pair<string, string>, int> freq;

    ll ans = 0;

    for (int i = 0; i < num_cities; i++)
    {
        string city, state;
        cin >> city >> state;
        
        string ini = city.substr(0, 2);

        if (ini == state) continue;

        ans += freq[{state, ini}];
        freq[{ini, state}]++;
    }
    
    freopen("citystate.out", "w", stdout);
    cout << ans << "\n";
    return 0;
}