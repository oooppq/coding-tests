/*
비슷한 유형의 문제를 풀었었는데,그게 bitwise로 바뀐 느낌.
금방 아이디어 떠올릴 수 있었는데, 아침 정신없음 이슈...
*/

class Solution
{
    bool check(vector<int> &dp)
    {
        for (int &num : dp)
        {
            if (num > 1)
                return false;
        }

        return true;
    }

public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(31, 0);
        int ret = 0;
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            bitset<31> bs(nums[i]);
            for (int j = 0; j < 31; j++)
                dp[j] += bs[j];

            while (!check(dp))
            {
                bitset<31> tmp(nums[s++]);
                for (int j = 0; j < 31; j++)
                    dp[j] -= tmp[j];
            }

            ret = ret > i - s + 1 ? ret : i - s + 1;
        }

        return ret;
    }
};