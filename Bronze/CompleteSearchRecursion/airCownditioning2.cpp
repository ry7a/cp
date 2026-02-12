#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int num_cows, num_airs;
    cin >> num_cows >> num_airs;

    vector <int> temperature (101, 0);
    for (int i = 0; i < num_cows; i++)
    {
        int s, t, c;
        cin >> s >> t >> c;
        
        temperature[s] += c;
        temperature[t+1] -= c;
    }

    vector <pair <int, int>> air_locations (num_airs);
    vector <int> air_cost(num_airs);
    vector <int> cooling(num_airs);

    for (int i = 0; i < num_airs; i++)
    {
        cin >> air_locations[i].first >> air_locations[i].second >> cooling[i] >> air_cost[i];
    }   

    int ans = INT32_MAX;
    for (int b = 0; b < (1 << num_airs); b++)
    {
        vector <int> temporary_temperature = temperature;
        int cost = 0;
        for (int i = 0; i < num_airs; i++)
        {
            if (b & (1 << i))
            {
                temporary_temperature[air_locations[i].first] -= cooling[i];
                temporary_temperature[air_locations[i].second + 1] += cooling[i];
                cost += air_cost[i];
            }
        }

        int t = 0;
        bool valid = true;
        for (int j = 1; j <= 100; j++)
        {
            t += temporary_temperature[j];
            if (t > 0)
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            ans = min(ans, cost);
        }
    }

    cout << ans << endl;

    return 0;
}