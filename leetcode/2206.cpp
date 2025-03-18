/*
걍 개쉬움. 그냥 배열에 빈도 기록해서 해도 충분할듯
*/

class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if ((i % 2) && nums[i - 1] != nums[i])
                return false;
        }
        return true;
    }
};