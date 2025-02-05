/*
코멘트할 것 없음. 아주 쉬운 문제.
이런 문제 특징은 max값을 매 순간 갱신해주는게 가장 편한 방법이라는 것..
*/

class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int ret = 0;
        int maxSum = 0;
        int prev = 0;
        for (int &num : nums)
        {
            if (prev < num)
                maxSum += num;
            else
                maxSum = num;

            if (ret < maxSum)
                ret = maxSum;
            prev = num;
        }

        return ret;
    }
};