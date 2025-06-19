/*
어렵지 않은 문제
*/

class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int ret = 1;
        int minNum = nums[0];

        for (int num : nums)
        {
            if (num - minNum > k)
            {
                ret++;
                minNum = num;
            }
        }

        return ret;
    }
};