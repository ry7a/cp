#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    int b1, b2, s1, s2, g1, g2, p1, p2;
    cin >> b1 >> b2;
    cin >> s1 >> s2;
    cin >> g1 >> g2;
    cin >> p1 >> p2;

    int bs, sg, gp;
    bs = (s2-s1) + (g2-g1) + (p2-p1);
    sg = (g2-g1) + (p2-p1);
    gp = p2-p1;
    
    cout << bs << "\n";
    cout << sg << "\n";
    cout << gp << "\n";

    return 0;
}