/*
뭐 이런게 미디움인가 싶을 정도로 쉬운 문제..
*/

class Solution
{
public:
    long long coloredCells(int n)
    {
        long long ret = 1;
        for (int i = 0; i < n; i++)
            ret += 4 * i;
        return ret;
    }
};