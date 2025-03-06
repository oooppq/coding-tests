/*
쉬운 문제. 아이디어조차 필요없다.
*/

class Solution
{
public:
    int minLength(string s)
    {
        int i = -1;
        int j = -1;
        while ((i = s.find("AB")) != -1 || ((j = s.find("CD")) != -1))
        {
            if (i != -1)
                s = s.substr(0, i) + s.substr(i + 2);
            else
                s = s.substr(0, j) + s.substr(j + 2);
        }

        return s.length();
    }
};