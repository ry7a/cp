#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    vector <int> flowers(n+1);    
    for (int i = 1; i <= n; i++) { cin >> flowers[i]; }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int avg = 0;
            for (int k = i; k <= j; k++)
            {
                avg += flowers[k];
            }
            if (avg % (j-i+1) != 0) continue;
            avg /= (j-i+1);

            bool findAvgFlower = false;
            for (int k = i; k <= j; k++)
            {
                if (flowers[k] == avg) { findAvgFlower = true; }
            }

            if (findAvgFlower) {ans++;}
        }
    }

    cout << ans << endl;
    return 0;
}