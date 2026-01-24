#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    freopen("censor.in", "r", stdin);
    string textFromMagazine;
    string censorWord;
    cin >> textFromMagazine >> censorWord;

    string censored;

    for(int i = 0; i < textFromMagazine.size(); i++)
    {
        censored += textFromMagazine[i];
        if (censored.size() > censorWord.size() && censored.substr(censored.size() - censorWord.size()) == censorWord)
        { 
            censored.resize(censored.size() - censorWord.size());
        }
    }
    
    freopen("censor.out", "w", stdout);
    cout << censored << endl;
    return 0;
}