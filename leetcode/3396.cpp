/*
그냥 쉬운 문제.
*/

class Solution
{
    int check(vector<int> &counts)
    {
        for (int &c : counts)
        {
            if (c > 1)
                return false;
        }

        return true;
    }

public:
    int minimumOperations(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> counts(101, 0);
        int ret = 0;
        for (int &num : nums)
        {
            counts[num]++;
        }

        int i = 0;
        while (!check(counts))
        {
            int lim = min(i + 3, n);
            while (i < lim)
                counts[nums[i++]]--;
            ret++;
        }

        return ret;
    }
};