/*
되게 무식한 방법으로 풀긴 했음.
걍 공백은 하나만 남기고, 좌우 스왑하는 방식도 괜찮을듯.
*/

class Solution
{
public:
    string reverseWords(string s)
    {
        string ret = "";
        string buffer = "";
        s += " ";

        for (char c : s)
        {
            if (c == ' ')
            {
                if (!buffer.length())
                    continue;

                if (ret.length())
                    buffer.push_back(' ');
                ret = buffer + ret;
                buffer = "";
            }
            else
                buffer.push_back(c);
        }

        return ret;
    }
};