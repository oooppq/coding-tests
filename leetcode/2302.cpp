/*
약간 뭐에 씌였는지, 걍 슬라이딩 윈도우로 풀면 되는데, 어리석게 풀었다.
바보녀석. hard긴 한데 hard는 아니고 미디움정도?
*/

class Solution
{
public:
    bool check(vector<long long> &dp, int s, int e, long long k)
    {
        int len = e - s + 1;
        long long sum = dp[e];
        if (s > 0)
            sum -= dp[s - 1];

        return sum * len < k;
    }

    long long countSubarrays(vector<int> &nums, long long k)
    {
        long long ret = 0;
        int n = nums.size();
        vector<long long> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
            dp[i] = nums[i] + dp[i - 1];
        int e = 0;
        for (int s = 0; s < n; s++)
        {
            e = max(s, e);
            ret += e - s;

            while (e < n && check(dp, s, e, k))
            {
                ret++;
                e++;
            }
        }
        return ret;
    }
};

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        int n = nums.size();
        long long res = 0, total = 0;
        for (int i = 0, j = 0; j < n; j++)
        {
            total += nums[j];
            while (i <= j && total * (j - i + 1) >= k)
            {
                total -= nums[i];
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};