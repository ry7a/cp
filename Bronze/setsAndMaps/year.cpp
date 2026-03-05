#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int MOD = 12;

map <string, int> years {
    {"Ox", 0},
    {"Tiger", 1},
    {"Rabbit", 2},
    {"Dragon", 3},
    {"Snake", 4},
    {"Horse", 5},
    {"Goat", 6},
    {"Monkey", 7},
    {"Rooster", 8},
    {"Dog", 9},
    {"Pig", 10},
    {"Rat", 11}
};

int main ()
{
    int num_sentences;
    cin >> num_sentences;
    // Ox, Tiger, Rabbit,
    // Dragon, Snake, Horse, 
    // Goat, Monkey, Rooster, 
    // Dog, Pig, Rat
    
    map <string, int> cows {{"Bessie", 0}};
    
    for (int i = 0; i < num_sentences; i++)
    {
        string cow1, trash, order, year, cow2;
        cin >> cow1 >> trash >> trash >> order >> year >> trash >> trash >> cow2;

        int year_name = abs((cows[cow2] % MOD + MOD) % MOD);
        if (order == "previous")
        {
            if (years[year] == year_name) { cows.insert({cow1, cows[cow2] - MOD});}
            if (years[year] > year_name) { cows.insert({cow1, cows[cow2] - (year_name + MOD - years[year])});}
            cows.insert({cow1, cows[cow2] - (year_name - years[year])});
        }
        else 
        {
            if (years[year] == year_name) { cows.insert({cow1, cows[cow2] + MOD});}
            if (years[year] > year_name) { cows.insert({cow1, cows[cow2] + (years[year] - year_name)}); }
            cows.insert({cow1, cows[cow2] + (years[year] + MOD - year_name)});
        }

        if (cow1 == "Elsie") break; 
    }

    cout << abs(cows["Elsie"]);

    return 0;
}