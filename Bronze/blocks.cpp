#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int N;
    cin >> N;

    vector <int> alphabetic(26);
    for (int i = 0; i < N; i++)
    {
        string a, b;
        cin >> a >> b;
        vector <int> letterUpwards (26);
        for (auto c : a)
        {
            letterUpwards[int(c)-97] += 1;
        }

        vector <int> letterDownwards (26);
        for(auto c : b)
        {
            letterDownwards[int(c) - 97] += 1;
        }
        
        for (int j = 0; j < 26; j++)
        {
            alphabetic[j] += max(letterDownwards[j], letterUpwards[j]);
        }
    }

    for (auto i : alphabetic) {cout << i << "\n";}
    return 0;
}