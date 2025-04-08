/*
bitset으로 풀면 어렵지않게 풀 수 있다.
n이 작기 때문에 마구마구 sort 해줘도 된다.
*/

class Solution
{
    int getSetBitNum(int num)
    {
        bitset<10> bs(num);
        int count = 0;
        for (int i = 0; i < bs.size(); i++)
        {
            if (bs[i])
                count++;
        }

        return count;
    }

public:
    bool canSortArray(vector<int> &nums)
    {
        int i = 0;
        int prevI = i;
        int prev = getSetBitNum(nums[i++]);

        while (i < nums.size())
        {
            int cur = getSetBitNum(nums[i]);
            if (prev != cur)
            {
                sort(nums.begin() + prevI, nums.begin() + i);
                prevI = i;
                prev = cur;
            }
            i++;
        }

        sort(nums.begin() + prevI, nums.begin() + i);

        prev = -1;

        for (int &num : nums)
        {
            if (num < prev)
                return false;
            prev = num;
        }

        return true;
    }
};