/*
leetcode/3306.cpp 문제의 쉬운 버전이다.
일반적인 substring은 중간에 건너뛰는거 없이 연결되어 있다는 것을 항상 명심하면서 풀어야 할 것이다.
 */
class Solution
{
    bool check(vector<int> &dp)
    {
        for (int i = 0; i < 3; i++)
        {
            if (dp[i] == 0)
                return false;
        }

        return true;
    }

public:
    int numberOfSubstrings(string str)
    {
        int ret = 0;
        int n = str.length();
        vector<int> dp(3);

        int s = 0;
        for (int e = 0; e < n; e++)
        {
            int idx = str[e] - 'a';
            dp[idx]++;

            if (check(dp))
            {
                ret++;
                while (s < e && dp[str[s] - 'a'] - 1 > 0)
                {
                    dp[str[s] - 'a']--;
                    s++;
                }
                ret += s;
            }
        }

        return ret;
    }
};