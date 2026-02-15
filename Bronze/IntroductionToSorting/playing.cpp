#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int num_tests;
    cin >> num_tests;

    while (num_tests--)
    {
        int num_cards, num_numbers;
        cin >> num_cards >> num_numbers;
                        
        vector <vector <int>> numbers (num_numbers, vector <int> (num_cards));
        for (int i = 0; i < num_cards; i++)
        {
            for (int j = 0; j < num_numbers; j++)
            {
                cin >> numbers[j][i];
            }
        }


        long long total_ammount = 0;
        for (int i = 0; i < num_numbers; i++)
        {
            sort(numbers[i].begin(), numbers[i].end());

            long long prefix = 0;

            for (int j = 0; j < num_cards; j++)
            {
                total_ammount +=  1LL*numbers[i][j]*j - prefix;
                prefix += numbers[i][j];
            }
        }

        cout << total_ammount << "\n";
    }

    return 0;
}