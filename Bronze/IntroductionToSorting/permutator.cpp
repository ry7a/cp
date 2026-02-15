#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    cin >> N;
    vector <long long> a(N);
    vector <long long> b(N);
    for (int i = 0; i < N; i++) { cin >> a[i]; a[i] *= (long long )(N - i)*(i + 1); }
    for (int i = 0; i < N; i++) { cin >> b[i]; }

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    long long ans = 0;

    for (int i = 0; i < N; i++)
    {
        ans += 1LL*a[i]*b[i];
    }

    cout << ans << endl;
    return 0;
}