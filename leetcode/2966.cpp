/*
쉬운 문제였다.
*/

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int m = n / 3;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret(m, vector<int>(3, 0));
        for (int k = 0; k < n; k++)
        {
            ret[k / 3][k % 3] = nums[k];
        }

        for (int i = 0; i < m; i++)
        {
            int prev = ret[i][0];
            for (int j = 0; j < 3; j++)
            {
                if (ret[i][j] == 0)
                    return {};
            }
            if (ret[i][2] - ret[i][0] > k)
                return {};
        }

        return ret;
    }
};
