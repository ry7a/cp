#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen("cownomics.in", "r", stdin);
    int cows, length;
    cin >> cows >> length;

    vector <set<char>> genomesSpotty (length+1);
    vector <set<char>> genomesPlain (length+1);

    for (int j = 0; j < cows; j++)
    {
        for (int i = 1; i <= length; i++)
        {
            char genome;
            cin >> genome;
            genomesSpotty[i].insert(genome);
        }
    } 
    for (int j = 0; j < cows; j++)
    {
        for (int i = 1; i <= length; i++)
        {
            char genome;
            cin >> genome;
            genomesPlain[i].insert(genome);
        }
    }

    int ans = 0;
    for (int i = 1; i <= length; i++)
    {
        set <char> intersectionSet;
        set_intersection(genomesPlain[i].begin(), genomesPlain[i].end(), genomesSpotty[i].begin(), genomesSpotty[i].end(), inserter(intersectionSet, intersectionSet.begin()));
        if (intersectionSet.empty()) { ans++; }
    }

    freopen("cownomics.out", "w", stdout);
    cout << ans << endl;

    return 0;
}
