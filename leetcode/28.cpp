/*
걍 쉬운문제.
find 안써도 쉬움
*/

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int idx = haystack.find(needle);
        return idx;
    }
};