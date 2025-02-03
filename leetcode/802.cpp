#include <iostream>

class Solution
{
public:
    int flag[10001];
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> ret;

        for (int i = 0; i < graph.size(); i++)
            flag[i] = 0;
        for (int i = 0; i < graph.size(); i++)
        {
            if (r(graph, i))
                ret.push_back(i);
        }

        return ret;
    }

    bool r(vector<vector<int>> &graph, int idx)
    {
        if (flag[idx] > 1)
            return false;
        if (flag[idx] == 1)
            return true;
        if (graph[idx].size() == 0)
            return true;

        for (int j = 0; j < graph[idx].size(); j++)
        {
            flag[idx] = 2;
            if (r(graph, graph[idx][j]) == false)
            {
                flag[idx] = 3;
                return false;
            }
            flag[idx] = 0;
        }
        flag[idx] = 1;
        return true;
    }
};