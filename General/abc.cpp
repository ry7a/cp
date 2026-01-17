#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector <long long> v;
    long long x;
    while (cin >> x) {v.push_back(x);}
    sort(v.begin(), v.end());
    cout << v[0] << " " << v[1] << " ";

    if(v[2] == v[0] + v[1]) {cout << v[3];}
    else {cout << v[2];}

    return 0;
}