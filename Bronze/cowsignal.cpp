#include <iostream>
#include <cstdio>
using namespace std;

#define MAXM 11;
#define MAXN 11;

int main()
{
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    string line;
    string nline {""};    
    int M, N, K;
    char trash[2];
    cin >> M >> N >> K;
    for(int i = 0; i < M; i++)
    {
        cin >> line;
        nline = "";
        for (auto c : line) 
        {
            for(int j = 0; j < K; j++) {nline += c;}
        }
        for(int j = 0; j < K; j++) {cout << nline << "\n";}
    }

    return 0;
}