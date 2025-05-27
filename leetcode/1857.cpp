/*
아이디어가 안떠올라서 못풀었다.
답안 보니까 어렵진 않은듯.쓰벌취소.
dfs로 방문하는데, 각 노드에서의 최대개수를 갱신하면서 저장하면 된다.
중요한건 각 노드에 해당하는 색의 최대값만 고려하면 된다는 것.
만약 node A에서 갈 수 있는 끝까지 갔을 때 'a' - 'z'들의 count들 중 'c'가 가장 높더라도,
node A는 'b' 색이 칠해져 있다면, 'b'의 count만 고려하면 된다.
왜냐면, 끝까지 가는 path 중에서 어떤 node는 'c'가 칠해져 있을테고, 그 때가 최대값이었을 것이기 때문이다.
말로 설명하긴 어려운데 무튼 그렇다. 진짜 어려운 아이디어다.
아직 많이 부족하다진짜...
*/

class Solution
{
public:
    int dfs(int node, string &colors, vector<vector<int>> &adj, vector<vector<int>> &count, vector<int> &vis)
    {
        if (!vis[node])
        {
            vis[node] = 1;
            for (int next : adj[node])
            {
                if (dfs(next, colors, adj, count, vis) == INT_MAX)
                    return INT_MAX;
                for (int c = 0; c < 26; c++)
                    count[node][c] = max(count[node][c], count[next][c]);
            }
            ++count[node][colors[node] - 'a'];
            vis[node] = 2;
        }
        return vis[node] == 2 ? count[node][colors[node] - 'a'] : INT_MAX;
    }

    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size();
        vector<vector<int>> adj(n), count(n, vector<int>(26));
        vector<int> vis(n);
        for (auto &e : edges)
            adj[e[0]].push_back(e[1]);
        int ans = 0;
        for (int i = 0; i < n && ans != INT_MAX; i++)
            ans = max(ans, dfs(i, colors, adj, count, vis));
        return ans == INT_MAX ? -1 : ans;
    }
};