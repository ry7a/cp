#include <iostream>
using namespace std;

int main()
{
    int k, n, w;

    cin >> k >> n >> w;

    int money, ans;
    money = ((w + 1)*w*k)/2;

    if (money > n) {cout << (money - n);}
    else {cout << 0;}

    return 0;
}