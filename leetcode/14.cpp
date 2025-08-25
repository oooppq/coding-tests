/*
걍 쉬움.
substr으로도 풀수있고, 이분탐색으로도 풀 수 있음.
*/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ret = "";

        int n = 201;
        for (auto str : strs)
        {
            if (str.length() < n)
                n = str.length();
        }

        int idx = 0;
        while (idx < n)
        {
            bool flag = true;
            char comm = strs[0][idx];
            for (auto str : strs)
            {
                if (str[idx] != comm)
                {
                    flag = false;
                    break;
                }
            }

            if (!flag)
                break;
            ret.push_back(comm);
            idx++;
        }

        return ret;
    }
};