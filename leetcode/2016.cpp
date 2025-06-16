/*
걍 쉬움.
*/

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int ret = -1;
        int m = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] >= m)
                m = nums[i];
            else
                ret = max(ret, m - nums[i]);
        }

        return ret;
    }
};