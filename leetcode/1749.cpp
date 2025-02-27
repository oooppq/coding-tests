/*
자주 풀어본 유형의 문제. 그냥 매 반복마다 최대값을 계산해주면 된다.
*/

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int m1 = 0;
        int m2 = 0;
        int cum = 0;
        for (auto &num : nums)
        {
            if (cum < 0)
                cum = 0;
            cum += num;
            m1 = m1 > cum ? m1 : cum;
        }
        cum = 0;
        for (auto &num : nums)
        {
            if (cum > 0)
                cum = 0;
            cum += num;
            m2 = abs(m2) > abs(cum) ? m2 : cum;
        }

        return m1 > abs(m2) ? m1 : abs(m2);
    }
};