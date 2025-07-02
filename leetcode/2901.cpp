/*
진짜 오래걸려서 풀긴 했음...
어렵다. 아이디어가 좀 어려움.
내가 한건, 각 dp[i]에 이전에 포함한 애들을 전부 저장하도록 했는데,
그게아니고, 해당 i 방문 전 마지막으로 방문한 idx를 저장하면 역으로 추적할 수 있다.
*/

class Solution
{
public:
    int checkDist(string &s1, string &s2)
    {
        if (s1.length() != s2.length())
            return 0;
        int count = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
                count++;
            if (count > 1)
                return 0;
        }

        return count;
    }

    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
    {

        int n = words.size();
        vector<vector<string>> dp(n, vector<string>());
        for (int i = 0; i < n; i++)
            dp[i].push_back(words[i]);

        int maxCount = 0;
        int maxIdx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (checkDist(words[i], words[j]) && (dp[i].size() + 1 > dp[j].size()) && groups[i] != groups[j])
                {
                    vector<string> tmp = dp[i];
                    tmp.push_back(words[j]);
                    dp[j] = tmp;
                    if (dp[j].size() > maxCount)
                    {
                        maxCount = dp[j].size();
                        maxIdx = j;
                    }
                }
            }
        }

        return dp[maxIdx];
    }
};