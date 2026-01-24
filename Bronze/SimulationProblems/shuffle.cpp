#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int N;
    cin >> N;
    
    vector <int> rshuffle(N+1);
    vector <int> order(N+1);
    vector <int> id(N+1);
    for (int i = 1; i <= N; i++)
    {
        cin >> order[i];
    }
    for (int i = 1; i <= N; i++) 
    {
        cin >> id[i];
    }
    rshuffle = id;

    for(int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            id[j] = rshuffle[order[j]]; 
        }
        rshuffle = id;
    }

    for (int j = 1; j <= N; j++) 
    {
        cout << id[j] << "\n";
    }
    
    
    return 0;
}