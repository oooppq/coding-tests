/*
이런 문제는 뭔가 정렬하는 문제가 많은듯하다.
어렵진 않았고, 아이디어 떠올리는 데에 쪼금 걸렸다.
*/

class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        vector<bool> check(days + 1);
        int ret = 0;
        struct cmp
        {
            bool operator()(pair<int, int> a, pair<int, int> b)
            {
                return a > b;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        for (vector<int> &meeting : meetings)
        {
            pq.push({meeting[0], 0});
            pq.push({meeting[1], 1});
        }
        int cnt = 0;
        int prev = 0;
        while (!pq.empty())
        {
            pair<int, int> t = pq.top();
            pq.pop();
            if (t.second == 0)
                cnt++;
            else
                cnt--;

            if (cnt == 0)
            {
                ret += t.first - prev + 1;
            }
            else if (cnt == 1 && t.second == 0)
            {
                prev = t.first;
            }
        }
        return days - ret;
    }
};