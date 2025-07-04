/*
leetcode/3304.cpp 의 어려운 버전.
3304 풀 때 이미 비슷하게 접근했어서 괜찮았다.
*/

class Solution
{
public:
    char kthCharacter(long long k, vector<int> &operations)
    {
        vector<int> ops;
        int toAdd = 0;

        while (k != 1)
        {
            int toSub = __lg(k);
            if (k == (1ll << toSub))
                toSub--;
            k -= (1ll << toSub);
            toAdd += operations[toSub];
        }
        return 'a' + (toAdd % 26);
    }
};