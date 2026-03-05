#include <bits/stdc++.h>
using namespace std;
using ll = long long;

unordered_set <ll> possible_values;

void solve (const vector <ll> & judge_rates, const set<ll> & values_remembered, ll first_element)
{
    for (int i = 1; i <= (int) judge_rates.size(); i++)
    {
        set <ll> temporary_remembered = values_remembered;
        temporary_remembered.erase(first_element);

        ll sum = first_element;
        ll initial_value;
        for (int j = i - 1; j >= 1; j--)
        {
            sum -= judge_rates[j];
            if (temporary_remembered.count(sum)) { temporary_remembered.erase(sum); }
        }

        initial_value = sum;
        sum = first_element;
        for (int j = i; j < (int) judge_rates.size(); j++)
        {
            sum += judge_rates[j];
            if (temporary_remembered.count(sum)) { temporary_remembered.erase(sum); }
            if (temporary_remembered.empty()) { break; }
        }

        if (temporary_remembered.empty()) { possible_values.insert(initial_value); }
    }

    cout << (ll) possible_values.size() << "\n";
}

int main ()
{
    int num_judges, num_scores;
    cin >> num_judges >> num_scores;

    vector <ll> judge_rates (num_judges);
    set <ll> values_remembered;

    for (auto & r : judge_rates) { cin >> r; }
    
    ll first_element;
    for (int i = 0; i < num_scores; i++)
    {
        ll num;
        cin >> num;
        if (!i) { first_element = num; }
        values_remembered.insert(num);
    }

    solve(judge_rates, values_remembered, first_element);

    return 0;
}