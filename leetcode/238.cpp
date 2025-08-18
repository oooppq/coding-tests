/*
그냥저냥 쉬운 문제.
*/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int prod = 1;
        int zeroCnt = 0;
        for (auto num : nums)
        {
            if (num == 0)
                zeroCnt++;
            else
                prod *= num;
        }

        vector<int> ret;
        for (auto num : nums)
        {
            int numToPush = prod;
            if (zeroCnt)
            {
                if (num != 0 || zeroCnt - 1 != 0)
                    numToPush = 0;
            }
            else
                numToPush /= num;

            ret.push_back(numToPush);
        }

        return ret;
    }
};