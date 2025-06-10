/*
걍 쉬운 문제.
*/

class Solution
{
public:
    int maxDifference(string s)
    {
        vector<int> count(26, 0);
        for (char &c : s)
            count[c - 'a']++;

        int oddMax = 1;
        int evenMin = 101;

        for (int i = 0; i < 26; i++)
        {
            if (count[i] % 2)
            {
                oddMax = max(oddMax, count[i]);
            }
            else
            {
                evenMin = min(evenMin, count[i]);
            }
        }
        return oddMax - evenMin;
    }
};