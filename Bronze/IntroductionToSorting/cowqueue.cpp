#include <bits/stdc++.h>
using namespace std;

int main ()
{   
    freopen("cowqueue.in", "r", stdin);
    int N;
    cin >> N;

    vector <pair <int, int>> cow_order (N);

    for (auto & c : cow_order)
    {
        cin >> c.first >> c.second;
    }

    sort(cow_order.begin(), cow_order.end());

    int hour = cow_order[0].first;
    for(auto c : cow_order)
    {
        if (c.first < hour)
        {
            hour += c.second;
        }
        else { hour = c.first + c.second; }
    }

    freopen("cowqueue.out", "w", stdout);
    cout << hour << "\n";
    
    return 0;
}