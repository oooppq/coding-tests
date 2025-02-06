/*
map, unordered_map을 알고는 있었지만 자주 사용하진 않았어서 이번에 문제 풀면서 쪼끔 익숙해졌다.
해결 방법을 쉽게 찾긴 했는데, 바보같은 실수했다. nC2 * 2 를 해야하는데, 그냥 n!을 해버렸다.
바보자식
*/

#include <unordered_map>

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        unordered_map<int, int> um;
        int n = nums.size();
        int ret = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int mult = nums[i] * nums[j];
                // if(um.find(mult) != um.end()) um[mult] += 1;
                // else um.insert({mult, 1});
                um[mult]++;
            }
        }

        for (auto e : um)
        {
            ret += e.second * (e.second - 1) / 2 * 8;
        }
        return ret;
    }
};