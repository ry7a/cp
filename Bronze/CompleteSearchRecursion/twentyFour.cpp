#include <bits/stdc++.h>
using namespace std;

void solve (const vector <int> &numbers, set <int> &results)
{
    if (numbers.size() == 1)
    {
        results.insert(numbers[0]);
    }
    else
    {
        for (int i = 0; i < (int) numbers.size(); i++)
        {
            for (int j = i + 1; j < (int) numbers.size(); j++)
            {
                vector <int> next;
                for (int k = 0; k < (int) numbers.size(); k++)
                {
                    if (k != i && k != j) { next.push_back(numbers[k]); }
                }
                int a = numbers[i], b = numbers[j];
                vector <int> candidates {
                    a + b,
                    a - b,
                    b - a,
                    a*b
                };

                for (auto v : candidates)
                {
                    next.push_back(v);
                    solve(next, results);
                    next.pop_back();
                }

                if (b != 0 && a % b == 0)
                {
                    next.push_back(a / b);
                    solve(next, results);
                    next.pop_back();
                }

                if (a != 0 && b % a == 0)
                {
                    next.push_back(b / a);
                    solve(next, results);
                    next.pop_back();
                }
            }
        }
    }
}

int main ()
{
    int N;
    cin >> N;

    vector <vector <int>> hands (N, vector <int> (4));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 4; j++) { cin >> hands[i][j]; }
    }

    for (int i = 0; i < N; i++)
    {
        set <int> results;
        solve(hands[i], results);

        int max_c = 0;
        for (auto c : results)
        {
            if ( c > 24) { continue; }
            max_c = max(max_c, c);
        }

        cout << max_c << "\n";
    }
    return 0;
}