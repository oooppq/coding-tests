/*
언젠가 풀어본 유형이라 금방 풀었는데, 자료형때문에 한 번 틀렸다.
int지만 곱하고 더하고 하는 연산이 있기 때문에 결과물은 int 범위를 넘을 수 있다는 것을 인지해야 한다.

*/

#include <queue>

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long long> pq;
        int ret = 0;
        for (int num : nums)
            pq.push((long long)num * -1);
        while (pq.top() * -1 < k)
        {
            long long f = pq.top();
            pq.pop();
            long long s = pq.top();
            pq.pop();
            pq.push(max(f, s) * 2 + min(f, s));
            ret++;
        }
        return ret;
    }
};