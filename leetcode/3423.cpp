/*
걍 개쉬운문제
*/

class Solution
{
public:
    int maxAdjacentDistance(vector<int> &nums)
    {
        nums.push_back(nums[0]);
        int ret = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            ret = max(abs(nums[i] - nums[i - 1]), ret);
        }
        return ret;
    }
};