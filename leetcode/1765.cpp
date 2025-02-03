/*
단순한 bfs 문제다.
*/
#include <algorithm>

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int m = isWater.size();
        int n = isWater[0].size();

        deque<pair<pair<int, int>, int>> q;

        vector<vector<int>> hMap(m, vector<int>(n));
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         hMap[i][j] = -1;
        //     }
        // }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j])
                {
                    q.push_back({{i, j}, 0});
                }
                isWater[i][j] = -1;
            }
        }

        while (q.size())
        {
            pair<pair<int, int>, int> p = q.front();
            q.pop_front();

            int i = p.first.first;
            int j = p.first.second;
            int h = p.second;

            if (isWater[i][j] != -1)
                continue;
            isWater[i][j] = h;

            if (i - 1 >= 0 && isWater[i - 1][j] == -1)
                q.push_back({{i - 1, j}, h + 1});
            if (i + 1 < m && isWater[i + 1][j] == -1)
                q.push_back({{i + 1, j}, h + 1});
            if (j - 1 >= 0 && isWater[i][j - 1] == -1)
                q.push_back({{i, j - 1}, h + 1});
            if (j + 1 < n && isWater[i][j + 1] == -1)
                q.push_back({{i, j + 1}, h + 1});
        }

        return isWater;
    }
};