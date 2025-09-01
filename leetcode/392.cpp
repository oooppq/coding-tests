/*
걍 쉬움
*/

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        for (char c : s)
        {
            int idx = t.find(c);
            if (idx < 0)
                return false;
            t = t.substr(idx + 1);
        }

        return true;
    }
};