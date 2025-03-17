/*
풀긴 풀었다. 그냥 priority_queue 써서 풀었는데, 이 방법도 맞고 바이너리 서치로 푼 답안도 맞는 듯 하다.
어려웠던 문제,,
*/

class Solution
{
public:
    struct cmp
    {
        bool operator()(pair<long long, int> a, pair<long long, int> b)
        {
            long long na = a.first * a.second * a.second;
            long long nb = b.first * b.second * b.second;

            if (na != nb)
                return na > nb;
            else
                return a.first * (2 * a.second + 1) > b.first * (2 * b.second + 1);
        }
    };
    long long repairCars(vector<int> &ranks, int cars)
    {
        long long ret = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, cmp> pq;

        for (int &r : ranks)
            pq.push(pair(r, 1));

        while (cars--)
        {
            pair<long long, int> t = pq.top();
            pq.pop();
            ret = t.first * t.second * t.second;
            pq.push(pair(t.first, t.second + 1));
        }
        return ret;
    }
};