#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main ()
{
    int distinct = 0;
    int n;
    cin >> n;
    map <ll, ll> numbers;
    while (n--)
    {
        ll x;
        cin >> x;
        if (numbers.count(x)) { continue; }
        distinct ++; numbers.insert({x, 1});
    }

    cout << distinct;

    return 0;
}