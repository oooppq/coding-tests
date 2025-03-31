/*
아이디어가 엄청 중요한 문제...
풀긴 풀었는데, 떠올리기 어렵긴 했다.
for(int i = v.size() - 1; i >= v.size() - k + 1; i--) maxNum += v[i];
일케 했을 때 문제가되는 이유는 v.size()가 unsigned 타입이기 때문에 - 연산 결과가 엄청나게 큰 수가 될 수 있기 때문이다.
재밌는 문제다.
*/

class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        vector<long long> v;
        int n = weights.size();
        for (int i = 1; i < n; i++)
        {
            v.push_back((long long)weights[i - 1] + (long long)weights[i]);
        }
        sort(v.begin(), v.end());

        long long minNum = 0;
        long long maxNum = 0;

        for (int i = 0; i < k - 1; i++)
            minNum += v[i];
        for (int i = n - 1 - 1; i >= n - 1 - k + 1; i--)
            maxNum += v[i];
        // for(int i = v.size() - 1; i >= v.size() - k + 1; i--) maxNum += v[i];
        return maxNum - minNum;
    }
};