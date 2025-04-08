/*
leetcode/2873.cpp와 똑같은데 n만 커진 문제.
O(n)으로 풀면 쉽게 풀 수 있다.
*/

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long imax = 0;
        long long lmax = 0;
        long long ret = 0;
        for (int k = 0; k < nums.size(); k++)
        {
            ret = max(ret, lmax * (long long)nums[k]);
            lmax = max(lmax, imax - (long long)nums[k]);
            imax = max(imax, (long long)nums[k]);
        }

        return ret;
    }
};