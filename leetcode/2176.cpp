/*
걍 쉬운 문제. 생각할것도없음
*/

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int ret = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int ni = nums[i];
                int nj = nums[j];
                if ((ni == nj) && ((i * j) % k == 0))
                    ret++;
            }
        }
        return ret;
    }
};