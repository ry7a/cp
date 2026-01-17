#include <iostream>
using namespace std;

int main()
{
    int n, y, x;
    cin >> n;

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        x = 0;
        for (int j = 1; j <= 3; j++)
        {
            cin >> y;
            if (y == 0) {x += 1;}
        }
        if (x < 2) {ans += 1;}
    }

    cout << ans << endl;
        
    return 0;
}