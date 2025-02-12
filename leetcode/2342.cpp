/*
쉽다. unordered_map은 어느정도 사용법을 익혔는데, stl의 container들은 어떤건 push고 어떤건 push_back이고
어떤건 insert고 아 복잡하다증말..
*/

#include <queue>

class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        int ret = -1;
        unordered_map<int, priority_queue<int>> um;

        for (int m : nums)
        {
            int tmp = 0;
            int n = m;
            while (n)
            {
                tmp += n % 10;
                n /= 10;
            }
            um[tmp].push(m);
        }

        for (auto elem : um)
        {
            if (elem.second.size() >= 2)
            {
                int tmp = elem.second.top();
                elem.second.pop();
                tmp += elem.second.top();

                ret = max(tmp, ret);
            }
        }
        return ret;
    }
};