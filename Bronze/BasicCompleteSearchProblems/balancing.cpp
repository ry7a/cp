#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("balancing.in", "r", stdin);
    int cows, boundary;
    cin >> cows >> boundary;

    vector <pair <int, int>> positions(cows);
    for (auto & p : positions) { cin >> p.first >> p.second; }

    int ans = INT32_MAX;
    for (int i = 0; i < cows; i++)
    {
        int X = positions[i].first + 1;
        for (int j = 0; j < cows; j++)
        {
            int Y = positions[j].second + 1;

            int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
            for (auto p : positions)
            {
                if (p.first > X && p.second > Y) q1++;
                else if (p.first < X && p.second > Y) q2++;
                else if (p.first < X && p.second < Y) q3++;
                else q4++;
            }
            int worst = max({q1, q2, q3, q4});
            ans = min(ans, worst);
        }
    }

    freopen("balancing.out", "w", stdout);
    cout << ans << endl;
    return 0;
}