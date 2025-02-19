/*
n과 k가 50이하이므로, 그냥 3 * 2^n 으로 모든 경우의수 다 돌리면 됐다.
*/

class Solution
{
    vector<string> ss;
    string happy = "abc";

public:
    string getHappyString(int n, int k)
    {
        r("", 0, n);

        return k > ss.size() ? "" : ss[k - 1];
    }

    void r(string s, int i, int n)
    {
        if (i >= n)
        {
            ss.push_back(s);
            return;
        }
        for (char c : happy)
        {
            if (!s.empty() && s.back() == c)
                continue;
            r(s + c, i + 1, n);
        }
    }
};

vector<vector<int>> vec(50, vector<int>(50, 0));