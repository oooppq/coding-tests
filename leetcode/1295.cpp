/*
거들떠 볼 것도 없는 문제
*/

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int ret = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int count = 0;
            while (num)
            {
                num /= 10;
                count++;
            }
            if (count % 2 == 0)
                ret++;
        }

        return ret;
    }
};