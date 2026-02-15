#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;   

    vector <int> weights (2*N);
    for (int &w : weights) { cin >> w; }

    sort(weights.begin(), weights.end());

    long long min_instability = LLONG_MAX;
    for (int i = 0; i < 2*N; i++)
    {
        for (int j = i + 1; j < 2*N; j++)
        {
            int p = -1;
            long long total_ammount = 0;    
            for (int k = 0; k < 2*N; k++)
            {
                if (k != i && k != j)
                {
                    total_ammount += p*weights[k];
                    p *= -1;
                }
            }

            min_instability = min(min_instability, total_ammount);
            
        }
    }

    cout << min_instability;

    return 0;
}