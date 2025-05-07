/*
뭔가 되게 어렵게 푼 느낌...
priority queue 사용하면 되는데,
아뭔가 버벅였다.
*/

typedef pair<pair<int, int>, int> elem;
int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution
{
    bool check(int i, int j, vector<vector<int>> &vis)
    {
        int n = vis.size();
        int m = vis[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        if (vis[i][j])
            return false;
        return true;
    }

public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int ret = 2501;
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        struct comp
        {
            bool operator()(elem l, elem r) { return l.second > r.second; }
        };

        priority_queue<elem, vector<elem>, comp> q;

        q.push({{0, 0}, 0});
        vis[0][0] = true;
        moveTime[0][0] = -1;
        while (!q.empty())
        {
            elem e = q.top();
            int i = e.first.first;
            int j = e.first.second;
            int t = e.second;

            q.pop();

            if (i == n - 1 && j == m - 1)
                return t;
            for (int k = 0; k < 4; k++)
            {
                int ni = i + dirs[k][0];
                int nj = j + dirs[k][1];
                if (check(ni, nj, vis))
                {
                    vis[ni][nj] = true;
                    int nt = t;
                    if (nt <= moveTime[ni][nj])
                        nt = moveTime[ni][nj];
                    q.push({{ni, nj}, nt + 1});
                }
            }
        }

        return ret;
    }
};