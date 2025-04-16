/*
풀긴 했는데, 어려웠다..
아이디어 생각해내기가 보통이 아니었다.
다시 풀어보길 권장.
*/

class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        unordered_map<int, int> um;
        int n = nums.size();
        long long ret = 0;

        int e = 0;
        int now = 0;

        for (int s = 0; s < n; s++)
        {
            while (e < n && now < k)
            {
                now += um[nums[e++]]++;
            }

            if (now < k)
                break;

            ret += n - e + 1;

            now -= --um[nums[s]];
        }

        return ret;
    }
};