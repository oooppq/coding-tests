/*
걍 개쉬움.
아주쉽진않나..?
*/

class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        vector<string> zero;
        vector<string> one;
        int n = words.size();

        int target0 = 0;
        int target1 = 1;

        for (int i = 0; i < n; i++)
        {
            if (groups[i] == target0)
            {
                zero.push_back(words[i]);
                target0 = (target0 + 1) % 2;
            }

            if (groups[i] == target1)
            {
                one.push_back(words[i]);
                target1 = (target1 + 1) % 2;
            }
        }

        return zero.size() > one.size() ? zero : one;
    }
};