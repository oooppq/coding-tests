/*
어렵진 않은데, 첫짜리가 0일 때의 처리를 어떻게하냐에서 좀 꼬였는데,
사실 그런 경우는 모든 원소가 0인 경우밖에 없기 때문에 크게 신경 안써도 됐던 문제..
*/

#include <algorithm>

bool compare(string a, string b)
{
    string add1 = a + b;
    string add2 = b + a;

    return add1 > add2;
}
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<int> numMap(10);
        string ret;

        vector<string> t;

        for (auto num : nums)
        {
            t.push_back(to_string(num));
        }

        sort(t.begin(), t.end(), compare);

        if (t[0] == "0")
            return "0";
        for (auto s : t)
            ret += s;

        // int i = 0;
        // while (ret[i] == '0')
        // {
        //     // cout << ret[i] << endl;
        //     i++;
        // }
        // ret = ret.substr(i);
        // if (ret.size() == 0)
        //     ret = "0";
        return ret;
    }
};