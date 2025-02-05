/*
이것도 graph의 cyclic을 확인하는 문제다(802번과 유사).
풀이에 실패했는데, 어려웠던 것은 cycle인 경우와 chain인 경우를 다르게 처리해야 한다는 것이다.
cycle인 경우 cycle 집합의 길이만 고려하면 되는데, chain의 경우 여러 chain이 하나의 테이블에 모이는 것이 가능하고,
체인의 모양이 단방향 체인과 쌍방향 체인이 있어, 무튼 복잡하다.
아래와 같이 푸는게 cycle 문제의 대표적인 풀이 방법인 듯 하다.
*/

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