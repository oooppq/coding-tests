/*
그냥저냥 쉬운 문제
*/

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> romanMap = {
            {'I', 0},
            {'V', 1},
            {'X', 2},
            {'L', 3},
            {'C', 4},
            {'D', 5},
            {'M', 6}};
        vector<int> nums = {1, 5, 10, 50, 100, 500, 1000};

        int sum = 0;
        int prev = 1001;
        for (char c : s)
        {
            int idx = romanMap[c];
            if (prev < nums[idx])
                sum += nums[idx] - prev * 2;
            else
                sum += nums[idx];

            prev = nums[idx];
        }

        return sum;
    }
};