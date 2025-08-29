/*
쉬움.
isalnum을 쓰면 더 쉬움.
*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string newS;
        for (auto c : s)
        {
            if (c >= 'A' && c <= 'Z')
                newS.push_back(c + 32);
            else if (c >= 'a' && c <= 'z')
                newS.push_back(c);
            else if (c >= '0' && c <= '9')
                newS.push_back(c);
        }
        int f = 0;
        int b = newS.length() - 1;

        while (f <= b)
        {
            if (newS[f] != newS[b])
                return false;
            ++f;
            --b;
        }

        return true;
    }
};