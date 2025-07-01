/*
그냥저냥 쉬운 문제
*/

class Solution
{
public:
    int possibleStringCount(string word)
    {
        int ret = 1;
        char prev = '0';

        for (char c : word)
        {
            if (prev == c)
                ret++;
            prev = c;
        }

        return ret;
    }
};