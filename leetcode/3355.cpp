/*
쉽진 않은 문제였으나 풀긴 함.
시작지점과 종료지점을 잘 설정해야 하는 문제인듯
내 풀이는 존나게 복잡한거고 풀이보니까 아는 유형이었다.
풀이를 잘 기억해내자.
*/

/*
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);

        for(vector<int>& q : queries) {
            dp[q[0]] += 1;
            dp[q[1] + 1] -= 1;
        }

        for(int i = 0; i < n; i++) {
            if(i > 0) dp[i] += dp[i - 1];
            if(nums[i] - dp[i] > 0) return false;
        }

        return true;
    }
};
*/

typedef pair<int, int> elem;
class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        bool ret = true;
        int n = nums.size();
        vector<int> toSub(n, 0);

        struct compare
        {
            bool operator()(elem l, elem r) { return l.first > r.first; }
        };

        priority_queue<elem, vector<elem>, compare> pq;

        for (vector<int> &q : queries)
        {
            pq.push({q[0], 0});
            pq.push({q[1] + 1, 1});
        }
        int now = 0;
        int s = 0;
        while (!pq.empty())
        {
            int e = pq.top().first;
            int isEnd = pq.top().second;
            pq.pop();

            for (int i = s; i < e; i++)
                toSub[i] = now;
            if (isEnd)
                now--;
            else
                now++;

            s = e;
        }

        for (int i = 0; i < n; i++)
        {
            nums[i] -= toSub[i];

            if (nums[i] > 0)
                return false;
        }
        return ret;
    }
};