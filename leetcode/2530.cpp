/*
아주 쉬운 문제. 자료형에 유의하자.
*/

class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        long long ret = 0;
        for (int &num : nums)
            pq.push(num);

        while (k-- > 0)
        {
            int mn = pq.top();
            pq.pop();
            ret += mn;
            pq.push(ceil(mn / 3.0));
        }

        return ret;
    }
};