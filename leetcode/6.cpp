/*
그냥 규칙성을 파악해서 푼 문제.
각 row마다 어떤 규칙으로 jump하는지 규칙을 파악하기만 하면 쉽다.
아이디어가 좀 어려웠지만 풀어서 뿌듯.
*/

class Solution
{
public:
    string convert(string s, int numRows)
    {
        string ret;
        int n = s.length();
        if (numRows < 2 || numRows >= n)
            return s;
        int interval = 2 * (numRows - 1);
        for (int i = 0; i < numRows; i++)
        {
            int j = i;

            int jump = 2 * i;
            while (j < n)
            {
                ret.push_back(s[j]);

                jump = interval - jump;
                if (jump == 0)
                    jump = interval;
                j += jump;
            }
        }
        return ret;
    }
};