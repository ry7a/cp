#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    vector <int> c(3);
    vector <int> f(3);
    for (int i = 0; i< 3; i++)
    {
        cin >> c[i] >> f[i];
    }

    int temp;
    for (int i = 0; i < 100; i++)
    {
        temp = min(f[i%3], c[(i+1)%3]-f[(i+1)%3]);
        f[i%3] -= temp;
        f[(i+1)%3] += temp;    
    }

    for(auto i : f) {cout << i << "\n";}

    return 0;
}