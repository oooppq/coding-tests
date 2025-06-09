/*
방향은 맞으나 시간초과 발생...
결국 못풀었다. 존나게 오래 붙잡고 있었는데 하
*/
class Solution
{
public:
    int findKthNumber(int n, int k)
    {
        int curr = 1;
        k--;

        while (k > 0)
        {
            int step = countSteps(n, curr, curr + 1);
            if (step <= k)
            {
                curr++;
                k -= step;
            }
            else
            {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }

private:
    int countSteps(int n, long prefix1, long prefix2)
    {
        int steps = 0;
        while (prefix1 <= n)
        {
            steps += min((long)(n + 1), prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return steps;
    }
};

/*
// 틀린 내코드...
// 시간초과가 발생함

class Solution {
    bool done = false;
    int count = 0;
    int ans = -1;

    void dfs(int num, int n, int k)
    {
        if(done) return;
        if(++count >= k)
        {
            ans = num;
            done = true;
        }

        if(1ll * num * 10 <= 1ll * n) dfs(num * 10, n, k);
        int lim = num - (num % 10) + 10;
        lim = lim < n + 1 ? lim : n + 1;
        if(num + 1 < lim) dfs(num + 1, n, k);
    }
public:
    int findKthNumber(int n, int k) {
        vector<int> arr;

        dfs(1, n, k);


        return ans;

    }
};
*/
