/*
정답 봤는데도 뭔말인지 모르겠다.
일단 내 풀이 방식이 틀린건 아닌거같은데, 시간초과가 뜬다.
dp를 쓰는건 맞는데, 흠...
*/

/*
vector<vector<int>> dp(10001, vector<int>(10001,0));
#define MOD 1000000007
class Solution {

public:
    int idealArrays(int n, int maxValue) {
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= maxValue; j++) {
                dp[i][j] = 0;
            }
        }

        int ret = 0;
        for(int i = 1; i <= maxValue; i++) ret =  (ret + recur(n, i)) % MOD;
        return ret;
    }

    int recur(int n, int now) {
        if(n == 1 || now == 1) return 1;
        if(dp[n][now]) return dp[n][now];
        int ret = 0;

        for(int i = 1; i <= now; i++) {
            if(now % i == 0) ret = (ret + recur(n - 1, i)) % MOD;
        }

        dp[n][now] = ret;
        return dp[n][now];
    }
};
*/

const int MOD = 1e9 + 7, MAX_N = 1e4 + 10,
          MAX_P = 15; // There are up to 15 prime factors
int c[MAX_N + MAX_P][MAX_P + 1];
vector<int> ps[MAX_N]; // List of prime factor counts
int sieve[MAX_N];      // Minimum prime factor

class Solution
{
public:
    Solution()
    {
        if (c[0][0])
        {
            return;
        }
        for (int i = 2; i < MAX_N; i++)
        {
            if (sieve[i] == 0)
            {
                for (int j = i; j < MAX_N; j += i)
                {
                    sieve[j] = i;
                }
            }
        }
        for (int i = 2; i < MAX_N; i++)
        {
            int x = i;
            while (x > 1)
            {
                int p = sieve[x];
                int cnt = 0;
                while (x % p == 0)
                {
                    x /= p;
                    cnt++;
                }
                ps[i].push_back(cnt);
            }
        }
        c[0][0] = 1;
        for (int i = 1; i < MAX_N + MAX_P; i++)
        {
            c[i][0] = 1;
            for (int j = 1; j <= min(i, MAX_P); j++)
            {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
            }
        }
    }
    int idealArrays(int n, int maxValue)
    {
        long long ans = 0;
        for (int x = 1; x <= maxValue; x++)
        {
            long long mul = 1;
            for (int p : ps[x])
            {
                mul = mul * c[n + p - 1][p] % MOD;
            }
            ans = (ans + mul) % MOD;
        }
        return ans;
    }
};