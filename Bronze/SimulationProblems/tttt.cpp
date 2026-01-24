#include <bits/stdc++.h>
using namespace std;

const int WIDTH = 3;

vector <string> board(WIDTH);
set<set<char>> winners[WIDTH+1];

void insert (vector <pair<int, int>> coordinates)
{
    set <char> contained;
    for(const pair<int, int> &p : coordinates) {contained.insert(board[p.first][p.second]);}

    winners[contained.size()].insert(contained);
}

int main()
{
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    for(int r = 0; r < WIDTH; r++) {cin >> board[r];}
    for(int i = 0; i < WIDTH; i++) {insert({{i, 0}, {i, 1}, {i, 2}});}
    for(int i = 0; i < WIDTH; i++) {insert({{0, i}, {1, i}, {2, i}});}
    insert({{0, 0}, {1, 1}, {2, 2}});
    insert({{2, 0}, {1, 1}, {0, 2}});

    cout << winners[1].size() << "\n";
    cout << winners[2].size() << "\n";
     
    return 0;
}