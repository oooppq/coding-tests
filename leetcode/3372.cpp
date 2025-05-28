/*
문제가 이해가 안돼서 좀 걸리긴 했는데, 기본적인 bfs dfs 문제다.
*/

class Solution
{
public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<int> count1(n, 0);
        vector<vector<int>> gr1(n, vector<int>());
        vector<vector<int>> gr2(m, vector<int>());

        for (auto &e : edges1)
        {
            gr1[e[0]].push_back(e[1]);
            gr1[e[1]].push_back(e[0]);
        }

        for (auto &e : edges2)
        {
            gr2[e[0]].push_back(e[1]);
            gr2[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++)
        {
            queue<pair<int, int>> q;
            q.push({i, 0});
            int count = 0;
            vector<int> vis(n, 0);
            while (!q.empty())
            {
                pair<int, int> node = q.front();
                vis[node.first] = 1;
                q.pop();
                if (node.second <= k)
                    count++;
                else
                    continue;
                for (int &next : gr1[node.first])
                {
                    if (!vis[next])
                        q.push({next, node.second + 1});
                }
            }
            count1[i] = count;
        }

        int maxNum = 0;
        for (int i = 0; i < m; i++)
        {
            queue<pair<int, int>> q;
            q.push({i, 0});
            int count = 0;
            vector<int> vis(m, 0);
            while (!q.empty())
            {
                pair<int, int> node = q.front();
                vis[node.first] = 1;
                q.pop();
                if (node.second < k)
                    count++;
                else
                    continue;
                for (int &next : gr2[node.first])
                {
                    if (!vis[next])
                        q.push({next, node.second + 1});
                }
            }
            maxNum = max(maxNum, count);
        }

        for (int i = 0; i < n; i++)
            count1[i] += maxNum;
        return count1;
    }
};