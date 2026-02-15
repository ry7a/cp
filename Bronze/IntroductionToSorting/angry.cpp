#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main ()
{
    freopen("angry.in", "r", stdin);
    int N;
    cin >> N;

    vector <ll> hay_bales (N);
    for (auto & h : hay_bales)
    {
        cin >> h;
    }

    sort(hay_bales.begin(), hay_bales.end());
    ll max_hay_bales = 0;
    for (int i = 0; i < N; i++)
    {
        ll destroyed = 1;
        int curr = i;
        int r = 1;

        while (true)
        {
            int next = curr;
            while(next - 1 >= 0 && hay_bales[curr] - hay_bales[next - 1] <= r)
            {
                next--;
            }

            if (next == curr) { break; }

            destroyed += curr - next;
            curr = next;
            r++;
        }

        curr = i;
        r = 1;
        while (true)
        {
            int next = curr;
            while (next + 1 < N && hay_bales[next + 1] - hay_bales[curr] <= r)
            {
                next++;
            }

            if (next == curr) { break; }

            destroyed += next - curr;
            curr = next;
            r++;
        }
        max_hay_bales = max(max_hay_bales, destroyed);
    }
    

    freopen("angry.out", "w", stdout);
    cout << max_hay_bales << "\n";

    return 0;
}
