class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int ret = 0;
        int maxLen = 0;
        int prev = 0;
        for (int &num : nums)
        {
            if (num > prev)
                maxLen++;
            else
            {
                if (ret < maxLen)
                    ret = maxLen;
                maxLen = 1;
            }
            prev = num;
        }
        if (ret < maxLen)
            ret = maxLen;

        maxLen = 0;
        prev = 51;
        for (int &num : nums)
        {
            if (num < prev)
                maxLen++;
            else
            {
                if (ret < maxLen)
                    ret = maxLen;
                maxLen = 1;
            }
            prev = num;
        }
        if (ret < maxLen)
            ret = maxLen;

        return ret;
    }
};