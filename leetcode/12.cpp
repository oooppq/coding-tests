/*
어렵진 않은데, 좋은 문제는 아닌듯
*/

class Solution
{
public:
    string intToRoman(int num)
    {
        unordered_map<int, string> um = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}};

        string ret = "";
        int dec = 1;
        while (num)
        {
            int now = num % 10;
            if (um.count(now * dec))
            {
                ret = um[now * dec] + ret;
            }
            else
            {
                string tmp = "";
                if (now >= 5)
                {
                    tmp += um[5 * dec];
                    now -= 5;
                }
                for (int i = 0; i < now; i++)
                {
                    tmp += um[dec];
                }
                ret = tmp + ret;
            }

            num /= 10;
            dec *= 10;
        }

        return ret;
    }
};