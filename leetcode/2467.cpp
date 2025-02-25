/*
풀이는 맞았는데, 파라미터를 잘못전달해서 시간초과 에러가 발생했다.
vector와 같은 자료형을 파라미터로 전달할 때에는, 특히 재귀 함수에 전달할 때에는
무조건 참조로 전달하자!! 그냥 전달하면 복사연산으로 인해 시간이 소요된다.
vis나 e의 경우 길이가 n이므로,O(n)의 시간복잡도가 매 재귀함수 호출마다 복사연산으로 소요되는 것이다.... 진짜 바보같은 실수!!!
*/

class Solution
{
    int ans = INT_MIN;

public:
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        int n = amount.size();

        vector<vector<int>> e(n);

        for (auto edge : edges)
        {
            e[edge[0]].push_back(edge[1]);
            e[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n);
        vis[0] = true;
        vector<int> trace;
        trace.push_back(0);
        pre(0, bob, vis, e, amount, trace);
        recur(0, vis, e, amount, 0);

        return ans;
    }

    void pre(int now, int bob, vector<int> &vis, vector<vector<int>> &e, vector<int> &amount, vector<int> &trace)
    {
        if (now == bob)
        {
            int n = trace.size();
            for (int i = n - 1; i >= (n + 1) / 2; i--)
                amount[trace[i]] = 0;
            if (n % 2)
                amount[trace[n / 2]] /= 2;
            return;
        }

        for (int cand : e[now])
        {
            if (vis[cand])
                continue;
            vis[cand] = true;
            trace.push_back(cand);
            pre(cand, bob, vis, e, amount, trace);
            trace.pop_back();
            vis[cand] = false;
        }
    }

    void recur(int now, vector<int> &vis, vector<vector<int>> &e, vector<int> &amount, int cumm)
    {
        bool flag = true;
        cumm += amount[now];
        for (int cand : e[now])
        {
            if (vis[cand])
                continue;
            flag = false;
            vis[cand] = true;
            recur(cand, vis, e, amount, cumm);
            vis[cand] = false;
        }

        if (flag)
            ans = cumm > ans ? cumm : ans;
    }
};