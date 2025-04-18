/*
어렵지 않은 문제
*/

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        string prevS = countAndSay(n - 1) + '0';

        char prevC = prevS[0];
        int count = 0;
        string ret;
        for (char &c : prevS)
        {
            if (prevC != c)
            {
                ret += to_string(count) + prevC;
                count = 0;
            }
            count++;
            prevC = c;
        }
        return ret;
    }
};