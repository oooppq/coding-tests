/*
어렵진 않았음.
최댓값을 구하는 로직을 window sliding 이후에 넣어야 하는게 포인트.
조건을 항상 잘 생각하자.
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        unordered_map<char, int> um;
        int ret = 0;
        int l = 0;

        for (int r = 0; r < n; r++)
        {
            um[s[r]]++;
            while (um[s[r]] > 1)
            {
                um[s[l]]--;
                l++;
            }
            ret = max(ret, r - l + 1);
        }

        return ret;
    }
};