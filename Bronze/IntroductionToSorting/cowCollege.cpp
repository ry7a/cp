#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int num_cows;
    cin >> num_cows;

    vector <long long> max_tuition (num_cows);
    for (auto & c : max_tuition) { cin >> c; }

    sort(max_tuition.begin(), max_tuition.end());
    
    long long tuition = 0;
    long long profit = 0;
    for (int i = 0; i < num_cows; i++)
    {
        long long local = max_tuition[i]*(num_cows-i);
        if (local > profit) { profit = local; tuition = max_tuition[i]; }
    }
    
    cout << profit << " " << tuition;

    return 0;
}