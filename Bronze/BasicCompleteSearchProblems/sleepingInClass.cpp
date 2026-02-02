#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test_num;
    cin >> test_num;

    for (int t = 0; t < test_num; t++)
    {
        int n;
        cin >> n;
        vector <int> elsie_log = vector <int> (n);
        int log_sum = 0;
        for (auto & h : elsie_log)
        {
            cin >> h;
            log_sum += h;
        }

        for (int num_hours = 0; num_hours <= log_sum; num_hours++)
        {
            if (num_hours != 0 && log_sum % num_hours != 0) { continue; }
            
            int curr_sum = 0;
            bool valid = true;
            for (int h : elsie_log)
            {
                curr_sum += h;
                if (curr_sum > num_hours)
                {
                    valid = false;
                    break;
                }
                else if (curr_sum == num_hours)
                {
                    curr_sum = 0;
                }
            }

            if(valid)
            {
                if (num_hours == 0)
                {
                    cout << 0 << endl;
                }
                else
                {
                    cout << n - log_sum / num_hours << endl;
                }
                break;
            }
        }
    }

        
    return 0;
}