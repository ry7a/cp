#include <bits/stdc++.h>
using namespace std;

const int LARGE = 1e9;

int main()
{
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int n;
    cin >> n;

    vector <int> maxCapacityRoom(n);
    for (int i = 0; i < n; i++) {cin >> maxCapacityRoom[i];}

    int minimum = LARGE;
    for(int i = 0; i < n; i++)
    {
        int amt = 0;
        for(int j = i+1; j < i+n; j++)
        {
            amt += maxCapacityRoom[j%n]*(j-i);
        }
        minimum = min(minimum, amt);
    }

    cout << minimum << "\n";

    return 0;
}