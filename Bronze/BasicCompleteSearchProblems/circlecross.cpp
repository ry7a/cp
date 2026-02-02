#include <bits/stdc++.h>
using namespace std;   

const int CIRCLE_LENGTH = 52;

int main ()
{
    freopen("circlecross.in", "r", stdin);
    string pathLog;
    cin >> pathLog;

    set <set <char>> crossingPairs;
    for (int i = 0; i < CIRCLE_LENGTH; i++)
    {
        for (int j = (i + 1)%CIRCLE_LENGTH; j != i; j = (j+1)%CIRCLE_LENGTH)
        {
            int counter = 0;
            int k = (i+1)%CIRCLE_LENGTH;
            while (pathLog[k] != pathLog[i])
            {
                if (pathLog[k] == pathLog[j])
                {
                    counter++;
                }
                k = (k+1)%CIRCLE_LENGTH;
            }

            set <char> crossingPair;
            if (counter%2) 
            { 
                crossingPair.insert(pathLog[i]); crossingPair.insert(pathLog[j]); 
            }

            if (!crossingPair.empty()) { crossingPairs.insert(crossingPair); }
        }
    }


    freopen("circlecross.out", "w", stdout);
    cout << crossingPairs.size() << endl;
    return 0;
}