/*
군집화하는게 중요한 문제. limit 이내의 차이를 가지는 값들을 군집화하고, 그들끼리 순서를 바꿔주는 방식이다.
통과는 했는데 시간은 엄청 오래걸렸다.
*/

#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        vector<int> ret(n);
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++)
        {
            p.push_back({nums[i], i});
        }

        struct
        {
            bool operator()(pair<int, int> a, pair<int, int> b) const { return a.first < b.first; }
        } compare;

        sort(p.begin(), p.end(), compare);

        vector<int> s;
        priority_queue<int> pq;
        s.push_back(p[0].first);
        pq.push(p[0].second);
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            if (abs(p[i].first - s.back()) <= limit)
            {
                std::cout << p[i].first << std::endl;
            }
            else
            {
                while (!s.empty())
                {
                    ret[pq.top()] = s.back();
                    pq.pop();
                    s.pop_back();
                }
            }
            s.push_back(p[i].first);
            pq.push(p[i].second);
        }

        while (s.size())
        {
            ret[pq.top()] = s.back();
            pq.pop();
            s.pop_back();
        }
        return ret;
    }
};