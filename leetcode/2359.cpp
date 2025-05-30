/*
간단한 dfs, bfs 문제.
이거도 문제가 뭔말하는지 이해를 못하겠어서 시간이좀 걸림..
*/

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &graph, vector<int> &dist, int l)
    {
        dist[node] = l;
        for (int &next : graph[node])
        {
            if (dist[next] >= 0)
                continue;
            dfs(next, graph, dist, l + 1);
        }
    }

    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int ret = -1;
        int tmp = 100001;
        int n = edges.size();
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n; i++)
        {
            if (edges[i] >= 0)
                graph[i].push_back(edges[i]);
        }

        vector<int> dist1(n, -1);
        dfs(node1, graph, dist1, 0);
        vector<int> dist2(n, -1);
        dfs(node2, graph, dist2, 0);

        for (int i = 0; i < n; i++)
        {
            if (dist1[i] < 0 || dist2[i] < 0)
                continue;
            int m = max(dist1[i], dist2[i]);
            if (m < tmp)
            {
                ret = i;
                tmp = m;
            }
        }
        return ret;
    }
};