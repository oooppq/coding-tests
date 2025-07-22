/*
살짝 아이디어가 필요하나 쉬운 문제.
*/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        vector<int> count(20001, 0);

        int idx = 0;
        count[nums[0] + 10000]++;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[idx] != nums[i] || count[nums[i] + 10000] < 2)
            {
                nums[++idx] = nums[i];

                count[nums[i] + 10000]++;
            }
        }

        return idx + 1;
    }
};