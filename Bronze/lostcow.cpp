#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, y;
    cin >> x >> y;

    int dir = 1;
    int dir_distance = 1;
    int total_distance = 0;
    while (true)
    {
        if ((dir == 1 && x <= y && (x+dir_distance) >= y) || (dir == -1 && y <= x && (x-dir_distance) <= y))
        {
            total_distance += abs(y-x);
            cout << total_distance;
            break;
        }
        else
        {
            dir *= -1;
            dir_distance *= 2;
            total_distance += dir_distance;
        }
    }

    return 0;
}