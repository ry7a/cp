#include <bits/stdc++.h>
using namespace std;

const int LARGE = 1e9;

int main()
{
    int N;
    cin >> N;

    vector <pair<int, char>> guesses (N);
    for (auto & guess : guesses) {cin >> guess.second >> guess.first;}
    
    sort(guesses.begin(), guesses.end());

    vector <int> lying_left(N);
    for (int i = 0; i < N; i++)
    {
        lying_left[i] += lying_left[i-1];
        if (guesses[i-1].second == 'L') {lying_left[i]++;}
    }

    vector <int> lying_right(N);
    for (int i = N-2; i >= 0; i--)
    {
        lying_right[i] += lying_right[i+1];

        if (guesses[i+1].second == 'G') { lying_right[i]++; }
    }

    int min_liars = N;
    for (int i = 0; i < N; i++)
    {
        min_liars = min(min_liars, lying_left[i] + lying_right[i]);
    }

    cout << min_liars << endl;
}