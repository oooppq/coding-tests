/*
어렵지 않게 풀었는데, 좀 복잡하게 풀었음
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int lim = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (lim < i)
                return false;
            lim = max(lim, i + nums[i]);
        }

        return true;
    }
};
걍이렇게 풀어도 됨.
 */

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                if (i == n - 1)
                    continue;

                bool flag = true;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (i < j + nums[j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    return false;
            }
        }
        return true;
    }
};
