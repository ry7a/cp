#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("pails.in", "r", stdin);
    int x, y, m;
    cin >> x >> y >> m;

    int sum = 0;
    int i = (int) m / x;
    int j = (int) m / y;
    int ans = -1;

    for (int a = 0; a <= i; a++)
   {
        for (int b = 0; b <= j; b++)
        {
            sum = a*x + b*y;
            if (sum > m) break;
            ans = max(ans, sum);        
        }
    }

    freopen("pails.out", "w", stdout);
    cout << ans << endl;

    return 0;
}