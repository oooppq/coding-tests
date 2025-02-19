/*
sort 미숙 이슈로 좀 걸리긴 했다.
물론 아이디어도 생각해내는데 좀 걸렸다.
어렵진 않은 문제였다.
답안 보니까 stack 사용하는 문제가 있다. I일 땐 계속 push-pop하고 D일 땐 push만 하면 된다.
개쩐다.
*/

class Solution
{
public:
    string smallestNumber(string pattern)
    {
        string ret;
        vector<int> nums;
        vector<int> points;
        int n = pattern.length();
        nums.push_back(1);
        char prev = pattern[0];
        for (int i = 0; i < n; i++)
        {
            if (pattern[i] != prev)
                points.push_back(i);
            nums.push_back(i + 2);
            prev = pattern[i];
        }

        pattern += pattern[pattern.length() - 1] == 'I' ? 'D' : 'I';
        points.push_back(n);
        int s = 0;
        for (int i = 0; i < points.size(); i++)
        {
            int e = points[i] + 1;

            if (pattern[points[i]] == 'I')
                sort(nums.begin() + s, nums.begin() + points[i] + 1, greater<int>());
            else
                sort(nums.begin() + s, nums.begin() + points[i] + 1, less<int>());
            s = points[i];
        }
        for (auto num : nums)
            ret += char('0' + num);
        return ret;
    }
};