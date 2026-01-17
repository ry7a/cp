#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int N, M;    
    cin >> N >> M;
    vector <int> v1(100), v2(100);

    int l, v, p = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> l >> v;
        for(int j = p; j < p+l; j++)
        {
            v1[j] = v;
        }
        p += l; 
    }

    p=0;
    for (int i = 0; i < M; i++)
    {
        cin >> l >> v;
        for(int j = p; j < p+l; j++)
        {
            v2[j] = v;
        }
        p += l;
    }
    
    int best = 0;
    int j = 0;
    for (int i = 0; i < 100; i++) { best = max(best, v2[i] - v1[i]);}

    cout << best;

    return 0;
}