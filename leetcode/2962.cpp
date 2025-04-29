/*
흔한 sliding window 문제
max_element라는 method는 처음 봤다.
유용하게 쓸 수 있을듯?
*/

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        long long ret = 0;
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());
        for (int s = 0, e = 0, count = 0; e < n; e++)
        {
            if (nums[e] == maxNum)
                count++;
            while (s <= e && count >= k)
            {
                if (nums[s++] == maxNum)
                    count--;
            }
            ret += s;
        }

        return ret;
    }
};