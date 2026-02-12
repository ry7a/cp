#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector <int> cowsOrder (N);
    for (int i = 0; i < N; i++) { cin >> cowsOrder[i]; }

    vector <int> doctorsOrder (N);
    for (int i = 0; i < N; i++) { cin >> doctorsOrder[i]; }

    vector <int> hits (N+1, 0);
    
    int correct_placement = 0;
    for (int i = 0 ; i < N; i++)
    {
        if(cowsOrder[i] == doctorsOrder[i]) { correct_placement++; }
    }

    for (int i = 0; i < N; i++)
    {
        int left = i;
        int right = i;

        int current_placement = 0;
        while (left >= 0 && right < N)
        {
            if (cowsOrder[left] == doctorsOrder[right]) { current_placement++; }
            if (cowsOrder[right] == doctorsOrder[left]) { current_placement++; }
            if (cowsOrder[left] == doctorsOrder[left]) { current_placement--; }
            if (cowsOrder[right] == doctorsOrder[right]) { current_placement--; }

            hits[current_placement + correct_placement]++;

            left--;
            right++;
        }
    }
    for (int i = 1; i < N; i++)
    {
        int left = i-1;
        int right = i;

        int current_placement = 0;
        while (left >= 0 && right < N)
        {
            if (cowsOrder[left] == doctorsOrder[right]) { current_placement++; }
            if (cowsOrder[right] == doctorsOrder[left]) { current_placement++; }
            if (cowsOrder[left] == doctorsOrder[left]) { current_placement--; }
            if (cowsOrder[right] == doctorsOrder[right]) { current_placement--; }

            hits[current_placement + correct_placement]++;

            left--;
            right++;
        }
    }

    for (auto h : hits) { cout << h << "\n"; }
    return 0;
}