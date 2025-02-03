#include <queue>
#include <algorithm>

class Solution
{
public:
    int maximumInvitations(vector<int> &favorite)
    {
        int chainLen = 0;
        int cycleLen = 0;
        int n = favorite.size();

        vector<int> in(n);
        for (int i = 0; i < n; i++)
        {
            in[favorite[i]]++;
        }

        queue<int> q;
        vector<int> depth(n, 1);

        for (int i = 0; i < n; i++)
        {
            if (in[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int cur = q.front();
            int nex = favorite[cur];
            q.pop();

            depth[nex] = max(depth[nex], depth[cur] + 1);
            if (--in[nex] == 0)
            {
                q.push(nex);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (in[i] == 0)
                continue;

            int s = i;
            int cur = i;
            int tmpLen = 0;
            while (in[cur] != 0)
            {
                in[cur] = 0;
                tmpLen++;
                cur = favorite[cur];
            }

            if (tmpLen == 2)
            {
                chainLen += depth[cur] + depth[favorite[cur]];
            }
            else
            {
                cycleLen = max(cycleLen, tmpLen);
            }
        }
        return max(chainLen, cycleLen);
    }
};