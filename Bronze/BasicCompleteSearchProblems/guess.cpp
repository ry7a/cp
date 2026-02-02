#include <bits/stdc++.h>
using namespace std;

template <typename T> set<T> intersection(const set<T> &s1, const set<T> &s2) 
{
	set<T> ret;
	for (const T &i : s1) {
		if (s2.count(i)) { ret.insert(i); }
	}
	return ret;
}

int main()
{
    freopen("guess.in", "r", stdin);
    int num_animals;
    cin >> num_animals;

    vector <set<string>> animals(num_animals);
    for (int i = 0; i < num_animals; i++)
    {
        string name;
        int attr_num;
        cin >> name >> attr_num;
        for (int j = 0; j < attr_num; j++)
        {
            string attr;
            cin >> attr;
            animals[i].insert(attr);
        }
    }

    int max_yes = 0;
    for (int a1 = 0; a1 < num_animals; a1++)
    {
        for (int a2 = a1 + 1; a2 < num_animals; a2++)
        {
            set <string> common = intersection(animals[a1], animals[a2]);
            max_yes = max(max_yes, (int)common.size() + 1);
        }
    }

    freopen("guess.out", "W", stdout);
    cout << max_yes << endl;
    return 0;
}