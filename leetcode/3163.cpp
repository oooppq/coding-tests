/*
딱히 어려울거 없는문제
*/

class Solution
{
public:
    string compressedString(string word)
    {
        string ret;
        char prev = word[0];
        int count = 0;
        for (char &c : word)
        {
            if (c != prev || count >= 9)
            {
                ret.push_back(count + '0');
                ret.push_back(prev);
                count = 0;
            }
            prev = c;
            count++;
        }

        ret.push_back(count + '0');
        ret.push_back(prev);
        return ret;
    }
};