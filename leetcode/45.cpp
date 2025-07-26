/*
어렵지 않음. 아이디어가 좀 필요.
*/

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> cnt(n, 10001);
        cnt[0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; (j <= i + nums[i]) && (j < n); j++)
            {
                if (cnt[i] + 1 < cnt[j])
                    cnt[j] = cnt[i] + 1;
            }
        }

        return cnt[n - 1];
    }
};