#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int N, K, x;
    cin >> N >> K;
    string s;

    x = K;
    int k;
    bool f = true;
    while (cin >> s)
    {
        k = s.size();
        if (f) {cout << s; f = false; x -= k; continue;}
        if ((x-k) < 0) {cout << "\n"; cout << s; x = K-k; continue;}
        cout << " " << s;
        x -= k;
    }

    return 0;
}