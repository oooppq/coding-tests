/*
답안의 풀이랑은 좀 다르게 풀긴 했음.
그냥, frequency가 0인 애는 넘어가고, 홀수인애는 1개만 남기고, 짝수인애는 2개만 남기면 되는
간단한 문제다.
*/

class Solution
{
public:
    int minimumLength(string s)
    {
        vector<int> dp(26, 0);
        for (char &c : s)
            dp[c - 'a']++;
        while (true)
        {
            bool flag = false;
            for (int i = 0; i < 26; i++)
            {
                if (dp[i] >= 3)
                {
                    dp[i] -= 2;
                    flag = true;
                }
            }
            if (!flag)
                break;
        }

        int ret = 0;
        for (int &count : dp)
            ret += count;

        return ret;
    }
};