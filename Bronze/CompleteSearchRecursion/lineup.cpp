#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen("lineup.in", "r", stdin);
    int num_constraints;
    cin >> num_constraints;
    
    vector <pair <string, string>> constraints (num_constraints);
    for (auto & c : constraints)
    {
        string trash;
        cin >> c.first;
        for (int i = 0; i < 4; i++) { cin >> trash; }
        cin >> c.second;
    }

    vector <string> sequence {"Beatrice", "Sue", "Belinda", "Bessie", "Betsy", "Blue", "Bella", "Buttercup"};
    sort(sequence.begin(), sequence.end());

    bool is_valid;
    do
    {
        is_valid = true;
        for (auto & c : constraints)
        {
            int pos1 = -1, pos2 = -1;
            for (int i = 0; i < 8; i++)
            {
                if (sequence[i] == c.first) pos1 = i;
                if (sequence[i] == c.second) pos2 = i;
            }

            if (abs(pos1 - pos2) != 1) 
            { 
                is_valid = false; 
                break;
            }
        }
        if (is_valid) { break; }
    } while (next_permutation(sequence.begin(), sequence.end()));
    
    freopen("lineup.out", "w", stdout);
    for (auto & s : sequence) { cout << s << "\n"; }
    return 0;   
}   