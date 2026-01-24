#include <bits/stdc++.h>
using namespace std;

const int LARGE =  1e9;

int main()
{
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int N;
    cin >> N;

    vector <string> segment_type(N);
    vector <int> start(N);
    vector <int> end(N);

    for(int m = 0; m < N; m++)
    {
        cin >> segment_type[m] >> start[m] >> end[m];
    }

    int low = 0;
    int high = LARGE;
    for (int m = N-1; m >= 0; m--)
    {
        if(segment_type[m] == "none")
        {
            low = max(low, start[m]);
            high = min(high, end[m]);
        }
        else if (segment_type[m] == "off")
        {
            low += start[m];
            high += end[m];
        }
        else if (segment_type[m] == "on")
        {
            low -= end[m];
            high -= start[m];
            low = max(low, 0);
        }
    }

    cout << low << ' ' << high << "\n";

    low = 0;
    high = LARGE;
    for (int m = 0; m < N; m++)
    {
        if(segment_type[m] == "none")
        {
            low = max(low, start[m]);
            high = min(high, end[m]);
        }
        else if (segment_type[m] == "on")
        {
            low += start[m];
            high += end[m];
        }
        else if (segment_type[m] == "off")
        {
            low -= end[m];
            high -= start[m];
            low = max(low, 0);
        }
    }

    cout << low << " " << high << "\n";

    return 0;
}