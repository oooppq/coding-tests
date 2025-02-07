/*
어제에 이어서 unordered_map을 사용한 문제이다. um에서 특정 key가 존재하는지 찾을 때,
um.find(key) != um.end() 를 많이 사용하는데, 그거보다 um.count(key)를 사용하는게 더 빠르다는 것을 알게 됐다.
그리고, um.size()도 O(1)이라는 것도... unordered_map을 잘 활용해야겠다.
*/

class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        unordered_map<int, int> cm;
        unordered_map<int, int> vm;
        vector<int> ret;
        ret.reserve(queries.size());

        for (auto &q : queries)
        {
            int ball = q[0];
            int color = q[1];

            if (vm.count(ball))
            {
                int prevColor = vm[ball];
                cm[prevColor]--;
                if (cm[prevColor] == 0)
                    cm.erase(prevColor);
            }

            vm[ball] = color;
            cm[color]++;

            ret.push_back(cm.size());
        }

        return ret;
    }
};