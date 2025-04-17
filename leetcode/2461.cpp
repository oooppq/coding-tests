/*
슬라이딩 윈도우로 풀면 됨.
쪼끔 오래걸리긴했는데, 어려운 문제는 아님.
*/

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> um;
        int n = nums.size();
        if (n < k)
            return 0;

        long long ret = 0;
        int count = 0;
        long long now = 0;
        for (int i = 0; i < n; i++)
        {
            now += (long long)nums[i];
            um[nums[i]]++;
            if (um[nums[i]] == 2)
                count++;

            if (i >= k)
            {
                now -= (long long)nums[i - k];
                um[nums[i - k]]--;
                if (um[nums[i - k]] == 1)
                    count--;
            }

            if (i >= k - 1 && count == 0)
                ret = max(ret, now);
        }

        return ret;
    }
};