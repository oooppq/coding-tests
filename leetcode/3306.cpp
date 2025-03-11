/*
걍 머리 개아픈 문젠데, 열심히 풀어서 결국 풀긴했다..
꼭 다시풀어보자.
*/

class Solution
{
    bool check(vector<int> &dp, int &k)
    {
        for (int i = 0; i < 5; i++)
        {
            if (dp[i] == 0)
            {
                return false;
            }
        }
        if (dp[5] != k)
            return false;

        return true;
    }

public:
    long long countOfSubstrings(string word, int k)
    {
        int n = word.length();
        int numVowel = 5;
        long long ret = 0;
        unordered_map<char, int> vowelMap = {
            {'a', 0},
            {'e', 1},
            {'i', 2},
            {'o', 3},
            {'u', 4},
            {'x', 5},
        };

        for (int i = 0; i < n; i++)
        {
            if (vowelMap.count(word[i]) == 0)
                word[i] = 'x';
        }

        vector<int> dp(6);

        int s = 0;
        int rs = -1;

        for (int e = 0; e < n; e++)
        {
            char c = word[e];
            int cIdx = vowelMap[c];
            dp[cIdx]++;
            while (dp[5] > k && s <= e)
            {
                rs = s;
                c = word[s++];
                cIdx = vowelMap[c];
                dp[cIdx]--;
            }

            if (check(dp, k))
            {
                c = word[s];
                cIdx = vowelMap[c];
                while (cIdx != 5 && dp[cIdx] - 1 > 0)
                {
                    dp[cIdx]--;
                    c = word[++s];
                    cIdx = vowelMap[c];
                }
                ret += s - rs;
            }
        }

        return ret;
    }
};
