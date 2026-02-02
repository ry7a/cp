#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("diamond.in", "r", stdin);
    int numberOfDiamonds, maxDifference;
    cin >> numberOfDiamonds >> maxDifference;
    
    vector <int> sizes (numberOfDiamonds);
    for (auto &diamond : sizes) { cin >> diamond;}

    int maxNumberOfDiamonsDisplayed = 0;
    for (int i = 0; i < maxNumberOfDiamonsDisplayed; i++)
    {
        int diamondsDisplayed = 0;
        for (int j = 0; j < maxNumberOfDiamonsDisplayed; j++)
        {
            int difference = abs(sizes[j]-sizes[i]);
            if (difference <= maxDifference) { diamondsDisplayed += 1;}
        }
        maxNumberOfDiamonsDisplayed = max(maxNumberOfDiamonsDisplayed, diamondsDisplayed);
    }

    freopen("diamond.out", "w", stdout);
    cout << maxNumberOfDiamonsDisplayed << endl;
    
    return 0;
}