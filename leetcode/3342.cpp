/*
어제 푼 문제랑 똑같은 문제.
유형으로 따지면 다익스트라 라고 한다..
가장 짧은거 먼저 하는거
*/

int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

class Solution
{
    struct elem
    {
        int i;
        int j;
        int t;
        int m;
    };

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
        struct compare
        {
            bool operator()(elem l, elem r) { return l.t > r.t; }
        };

        priority_queue<elem, vector<elem>, compare> pq;
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ret = 0;
        moveTime[0][0] = -1;
        pq.push({0, 0, 0, 1});
        vis[0][0] = true;

        while (!pq.empty())
        {
            elem e = pq.top();
            pq.pop();
            if (e.i == n - 1 && e.j == m - 1)
                return e.t;

            for (int k = 0; k < 4; k++)
            {
                int ni = e.i + dirs[k][0];
                int nj = e.j + dirs[k][1];
                if (check(ni, nj, vis))
                {
                    int nt = max(e.t, moveTime[ni][nj]) + e.m;
                    int nm = e.m % 2 + 1;
                    vis[ni][nj] = true;
                    pq.push({ni, nj, nt, nm});
                }
            }
        }
        return ret;
    }
};