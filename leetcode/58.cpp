/*
걍 쉬움
*/

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int ret = 0;
        bool flag = false;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                if (!flag)
                    flag = true;
                ret++;
            }
            else
            {
                if (flag)
                    break;
            }
        }

        return ret;
    }
};