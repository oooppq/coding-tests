/*
경로탐색 문제. 방문한 노드는 더이상 방문하지 않아도 되기 때문에 O(nm)일 것이다.
*/

class Solution
{
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<vector<int>> pre(n, vector<int>(n));
        vector<int> checked(n);
        vector<bool> ret(queries.size());
        for (int i = 0; i < prerequisites.size(); i++)
        {
            pre[prerequisites[i][0]][prerequisites[i][1]] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            r(pre, checked, i, n);
        }

        for (int i = 0; i < queries.size(); i++)
        {
            ret[i] = pre[queries[i][0]][queries[i][1]];
        }

        for (int i = 0; i < n; i++)
        {
            if (pre[0][i])
                std::cout << i << std::endl;
        }
        return ret;
    }

    void r(vector<vector<int>> &pre, vector<int> &checked, int cur, int n)
    {
        if (checked[cur])
            return;

        checked[cur] = 1;
        for (int j = 0; j < n; j++)
        {
            if (cur == j)
                continue;
            if (pre[cur][j])
            {
                if (checked[j] == 0)
                    r(pre, checked, j, n);

                for (int k = 0; k < n; k++)
                {
                    if (k == cur)
                        continue;
                    if (pre[j][k])
                    {
                        pre[cur][k] = 1;
                    }
                }
            }
        }
    }
};