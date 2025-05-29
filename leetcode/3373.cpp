/*
일단 틀렸다.
밑은 내가 틀린 풀이.
제일 처음에는 map의 key를 잘못설정해서 틀렸고(단순히 i + '0'으로 char 만들거나, 12 + 2가 1 + 12랑 똑같아지는거랑...),
그걸 수정하고 풀어도 memory limit에 걸려서 틀렸다.
되게 쉬운 규칙을 간과했다.
각 트리는 두 그룹으로 묶인다는 것.
0
|\
1 2
  |\
  3 4
이러한 트리가 있을 때, 0, 3,4가 모두 같은 값이고, 1,2가 같은 값이라는 것을 알면 개같은 뻘짓을 하지 않아도 된다ㅜㅜ
아래 주석은 모범답안이다. 하..나는왤케멍청할까
*/

class Solution
{
public:
    int dfs(int i, vector<vector<int>> &tree, vector<int> &vis, unordered_map<string, int> &um)
    {
        int ret = 0;
        vis[i] = 1;
        for (int &next : tree[i])
        {
            if (vis[next])
                continue;
            vis[next] = 1;
            for (int &ti : tree[next])
            {
                if (vis[ti])
                    continue;
                string ft = to_string(i) + "#" + to_string(ti);
                if (!um.count(ft))
                {
                    um[ft] = dfs(ti, tree, vis, um);
                }
                ret += um[ft];
            }
        }

        return ret + 1;
    }

    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        int n = edges1.size() + 1;
        unordered_map<string, int> um1;
        vector<vector<int>> t1(n, vector<int>());
        vector<int> c1(n, 0);

        for (auto &e : edges1)
        {
            t1[e[0]].push_back(e[1]);
            t1[e[1]].push_back(e[0]);
        }
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> vis(n, 0);
            c1[i] = dfs(i, t1, vis, um1);
            k = max(k, c1[i]);
        }
        int maxNum = 0;
        int m = edges2.size() + 1;
        unordered_map<string, int> um2;
        vector<vector<int>> t2(m, vector<int>());
        vector<int> c2(m, 0);

        for (auto &e : edges2)
        {
            t2[e[0]].push_back(e[1]);
            t2[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < m; i++)
        {
            vector<int> vis(m, 0);
            maxNum = max(maxNum, dfs(i, t2, vis, um2));
        }
        for (int i = 0; i < n; i++)
            c1[i] += maxNum;
        return c1;
    }
};

// class Solution {
// public:
//     int dfs(int node, int parent, int depth,
//             const vector<vector<int>>& children, vector<int>& color) {
//         int res = 1 - depth % 2;
//         color[node] = depth % 2;
//         for (int child : children[node]) {
//             if (child == parent) {
//                 continue;
//             }
//             res += dfs(child, node, depth + 1, children, color);
//         }
//         return res;
//     }

//     vector<int> build(const vector<vector<int>>& edges, vector<int>& color) {
//         int n = edges.size() + 1;
//         vector<vector<int>> children(n);
//         for (const auto& edge : edges) {
//             children[edge[0]].push_back(edge[1]);
//             children[edge[1]].push_back(edge[0]);
//         }
//         int res = dfs(0, -1, 0, children, color);
//         return {res, n - res};
//     }

//     vector<int> maxTargetNodes(vector<vector<int>>& edges1,
//                                vector<vector<int>>& edges2) {
//         int n = edges1.size() + 1, m = edges2.size() + 1;
//         vector<int> color1(n);
//         vector<int> color2(m);
//         vector<int> count1 = build(edges1, color1);
//         vector<int> count2 = build(edges2, color2);
//         vector<int> res(edges1.size() + 1);
//         for (int i = 0; i < n; i++) {
//             res[i] = count1[color1[i]] + max(count2[0], count2[1]);
//         }

//         cout << count1[0] << " " << count1[1] << endl;
//         cout << count2[0] << " " << count2[1] << endl;
//         return res;
//     }
// };