/*
그냥 뭐 거들떠도 안보는 문제
*/

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int negCount = 0;
        int posCount = 0;
        for (int &num : nums)
        {
            if (num < 0)
                negCount++;
            else if (num > 0)
                posCount++;
        }

        return max(negCount, posCount);
    }
};