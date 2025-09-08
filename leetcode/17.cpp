/*
backtracking인데, 그냥 dfs로 풀면 된다,
*/

class Solution
{
public:
    void dfs(string &digits, int idx, string s, vector<string> &ans)
    {
        if (idx >= digits.length())
        {
            ans.push_back(s);
            return;
        }

        for (char c : um[digits[idx]])
        {
            dfs(digits, idx + 1, s + c, ans);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() == 0)
            return ans;

        dfs(digits, 0, "", ans);
        return ans;
    }

    unordered_map<char, string> um =
        {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
};