#include <bits/stdc++.h>
using namespace std;

map<string,int> milked_cows = {
        {"Bessie",0}, {"Elsie",0}, {"Daisy",0},
        {"Gertie",0}, {"Annabelle",0},
        {"Maggie",0}, {"Henrietta",0}
    };

int main ()
{
    freopen("notlast.in", "r", stdin);
    int num_entries;
    cin >> num_entries;

    int minimun_amt = INT32_MAX;
    int sec_min = INT32_MAX;
    for (int i = 0 ; i < num_entries; i++)
    {
        string cow; int amt_milk;
        cin >> cow >> amt_milk;

        milked_cows[cow] += amt_milk;
    }

    for (auto & p : milked_cows)
    {
        if (p.second < minimun_amt) { minimun_amt = p.second; }
    }

    for (auto & p : milked_cows)
    {
        if (p.second > minimun_amt) { sec_min = min(sec_min, p.second); }
    }

    string cow;
    int counter = 0;
    for (auto & c : milked_cows)
    {
        if (c.second == sec_min) { counter++; cow = c.first; }
    }

    freopen("notlast.out", "w", stdout);
    
    cout << (counter == 1 ? cow : "Tie");

    return 0;
}