#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
char CANVAS[MAXN][MAXN];
int N, U;
long long ans = 0;

int blockCost(int i, int j) {
    map<char,int> occ {{'#',0},{'.',0}};
    occ[CANVAS[i][j]]++;
    occ[CANVAS[i][N+1-j]]++;
    occ[CANVAS[N+1-i][j]]++;
    occ[CANVAS[N+1-i][N+1-j]]++;
    return min(occ['#'], occ['.']);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> U;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> CANVAS[i][j];

    for(int i = 1; i <= N/2; i++)
        for(int j = 1; j <= N/2; j++)
            ans += blockCost(i, j);

    cout << ans << "\n";

    while(U--) {
        int r, c;
        cin >> r >> c;

        int bi = min(r, N+1-r);
        int bj = min(c, N+1-c);

        // remove contribuição antiga
        ans -= blockCost(bi, bj);

        // inverte
        CANVAS[r][c] = (CANVAS[r][c] == '#' ? '.' : '#');

        // adiciona nova contribuição
        ans += blockCost(bi, bj);

        cout << ans << "\n";
    }
}