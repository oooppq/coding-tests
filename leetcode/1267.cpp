/*
m, n이 최대 250이기 때문에 O(mn2) 혹은 O(m2n)으로 풀어도 된다.
범위가 작은 경우 O(n3)도 가능하다는 힌트가 될 수 있기 때문에 항상 확인해볼 것..
모든 서버의 개수에서 i,j에 위치한 서버에 대해 i행이나 j열에 다른 서버가 하나도 없다면 이를 제거하는 방식으로 풀면 된다.
*/

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