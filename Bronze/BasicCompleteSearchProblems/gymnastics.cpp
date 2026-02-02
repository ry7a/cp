#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("gymnastics.in", "r", stdin);
    int numberOfSessions, numberOfCows;
    cin >> numberOfSessions >> numberOfCows;

    int ** table;
    table = new int*[numberOfCows+1];
    for (int i = 1; i <= numberOfCows; i++) { table[i] = new int[numberOfSessions]; }

    for (int i = 0; i < numberOfSessions; i++)
    {
        for (int j = 1; j <= numberOfCows; j++) 
        { 
            int cow;
            cin >> cow;
            table[cow][i] = j; 
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= numberOfCows; i++)
    {
        for (int j = i + 1; j <= numberOfCows; j++)
        {
            bool isConsistent = true;
            bool past;
            for (int k = 0; k < numberOfSessions; k++)
            {
                bool isGreater = false;
                if (table[i][k] > table[j][k]) { isGreater = true;}
                if (k == 0) { past = isGreater;}

                if (past ^ isGreater) { isConsistent = false; break;}
            }

            if (isConsistent) { ans += 1; }
        }
    }

    freopen("gymnastics.out", "w", stdout);
    cout << ans << endl;

    return 0;
}