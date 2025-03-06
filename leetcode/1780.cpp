/*
쉬운 문제. 내 풀이처럼 안하고, 그냥 계속 빼다가 0보다 작아지는걸로 판단해도 된다.
*/

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        vector<int> ts;
        int lim = 10000000;
        int t = 1;
        // int i = 0;
        while (t < lim)
        {
            ts.push_back(t);
            t *= 3;
        }

        for (int i = ts.size() - 1; i >= 0; i--)
        {
            if (ts[i] <= n)
                n -= ts[i];
            if (n < 0)
                break;
        }

        return n == 0;
    }
};