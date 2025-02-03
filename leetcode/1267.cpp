class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                    count++;
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    bool flag = true;
                    for (int k = 0; k < m; k++)
                    {
                        if (k == i)
                            continue;
                        if (grid[k][j])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag)
                        continue;

                    for (int k = 0; k < n; k++)
                    {
                        if (k == j)
                            continue;
                        if (grid[i][k])
                        {
                            flag = false;
                            break;
                        }
                    }

                    if (flag)
                        count--;
                }
            }
        }

        return count;
    }
};