/*
string의 길이가 1,000 이하이기 때문에 O(n^2)로 풀어도 된다.
아이디어가 조금 필요하지만 크게 어려운 문제는 아녔다.
*/

class Solution
{
public:
    void dfs(int c, int &minC, vector<vector<int>> &dp, vector<bool> &vis)
    {
        if (vis[c])
            return;
        vis[c] = true;
        if (c < minC)
            minC = c;
        for (int &nc : dp[c])
        {
            dfs(nc, minC, dp, vis);
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        vector<vector<int>> dp(26, vector<int>());
        int n = s1.length();
        for (int i = 0; i < n; i++)
        {
            dp[s1[i] - 'a'].push_back(s2[i] - 'a');
            dp[s2[i] - 'a'].push_back(s1[i] - 'a');
        }

        for (int i = 0; i < baseStr.length(); i++)
        {
            int minC = 'A';
            vector<bool> vis(26, false);
            dfs(baseStr[i] - 'a', minC, dp, vis);
            baseStr[i] = minC + 'a';
        }

        return baseStr;
    }
};