/*
문제의 조건이 뭔가 명확하지 않긴한데, 쉬움
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> um;

        for (auto num : nums)
        {
            um[num]++;
            if (um[num] > nums.size() / 2)
                return num;
        }

        return 0;
    }
};