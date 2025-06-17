/*
어렵지 않음.
그냥 간단한 dfs 문제.
*/

class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int m, int n, int &sum)
    {
        sum += grid[i][j];
        grid[i][j] = 0;

        int dirs[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int d = 0; d < 4; d++)
        {
            int ni = i + dirs[d][0];
            int nj = j + dirs[d][1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj])
                dfs(grid, ni, nj, m, n, sum);
        }
    }

    int findMaxFish(vector<vector<int>> &grid)
    {
        int ret = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    int sum = 0;
                    dfs(grid, i, j, m, n, sum);
                    ret = max(ret, sum);
                }
            }
        }

        return ret;
    }
};