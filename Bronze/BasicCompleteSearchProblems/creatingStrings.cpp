#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string auxiliar;
string name;
set <string> permutations;

void permutation(vector <bool> chosen)
{
    if ((int) auxiliar.length() == (int) name.length()) { permutations.insert(auxiliar); }
    else
    {
        for (int i = 0; i < (int) name.length(); i++)
        {
            if (chosen[i]) { continue; }
            chosen[i] = true;
            auxiliar.push_back(name[i]);
            permutation(chosen  );
            chosen[i] = false;
            auxiliar.pop_back();
        }
    }
}

int main ()
{
    auxiliar.erase();
    cin >> name;
    vector <bool> chosen((int) name.length(), false);
    permutation(chosen);

    cout << (int) permutations.size() << "\n";
    for (auto s : permutations) { cout << s << "\n"; }
    return 0;
}