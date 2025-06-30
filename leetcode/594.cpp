/*
easy긴 했는데, 안 medium 정도 되는듯.
지금은 sort도하고 map도 썼는데, 걍 map이면 충분.
sort로도 되는듯하고..
*/

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        int ret = 0;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> um;
        for (int n : nums)
            um[n]++;

        int prev = nums[0];
        for (int n : nums)
        {
            if (n != prev)
            {
                if (n - prev == 1)
                    ret = max(ret, um[n] + um[prev]);
                prev = n;
            }
        }

        return ret;
    }
};