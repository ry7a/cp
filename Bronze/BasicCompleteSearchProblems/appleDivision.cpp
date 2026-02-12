#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int num_apples;
vector <ll> weights;

ll recurse_apples (int index, ll sum1, ll sum2)
{
    if (index == num_apples) { return abs(sum1 - sum2); }
    return min(recurse_apples(index + 1, sum1 + weights[index], sum2), recurse_apples(index + 1, sum1, sum2 + weights[index]));
}

int main ()
{
    cin >> num_apples;

    weights.resize(num_apples);
    for (auto & a : weights) { cin >> a; }

    cout << recurse_apples(0, 0, 0) << endl;
    return 0;
}