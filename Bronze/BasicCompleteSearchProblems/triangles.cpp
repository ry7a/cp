    #include <bits/stdc++.h>
    using namespace std;

    int main ()
    {
        freopen("triangles.in", "r", stdin);
        int numberOfFences;
        cin >> numberOfFences;

        vector <pair <int, int>> fences (numberOfFences);
        for (auto & fence : fences) { cin >> fence.first >> fence.second; }

        int maxArea = 0;
        for (int i = 0; i < numberOfFences; i++)
        {
            for (int j = 0; j < numberOfFences; j++)
            {
                if (fences[i].first == fences[j].first)
                {
                    for (int k = 0; k < numberOfFences; k++)
                    {
                        if (fences[i].second == fences[k].second)
                        {
                            int deltaX = abs(fences[i].first - fences[k].first);
                            int deltaY = abs(fences[i].second - fences[j].second);
                            maxArea = max(maxArea, deltaX*deltaY);
                        }
                    }
                }
            }
        }
        freopen("triangles.out", "w", stdout);
        cout << maxArea << endl;

        return 0;
    }