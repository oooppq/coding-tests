/*
주석친게 정답.
나는 시간초과.
어차피 힌트보고 풀었으니...
아이디어가 어렵진 않은데 시간이 진짜 빡빡하다.
다시 풀 가치가 있나...
*/

// class Solution {
// private:
//     int digit[100];

// public:
//     long long kMirror(int k, int n) {
//         auto isPalindrome = [&](long long x) -> bool {
//             int length = -1;
//             while (x) {
//                 ++length;
//                 digit[length] = x % k;
//                 x /= k;
//             }
//             for (int i = 0, j = length; i < j; ++i, --j) {
//                 if (digit[i] != digit[j]) {
//                     return false;
//                 }
//             }
//             return true;
//         };

//         int left = 1, count = 0;
//         long long ans = 0;
//         while (count < n) {
//             int right = left * 10;
//             // op = 0 indicates enumerating odd-length palindromes
//             // op = 1 indicates enumerating even-length palindromes
//             for (int op = 0; op < 2; ++op) {
//                 // enumerate i'
//                 for (int i = left; i < right && count < n; ++i) {
//                     long long combined = i;
//                     int x = (op == 0 ? i / 10 : i);
//                     while (x) {
//                         combined = combined * 10 + x % 10;
//                         x /= 10;
//                     }
//                     if (isPalindrome(combined)) {
//                         ++count;
//                         ans += combined;
//                     }
//                 }
//             }
//             left = right;
//         }
//         return ans;
//     }
// };

class Solution
{
    string convert(long long n, int k)
    {
        string s;
        while (n)
        {
            s = to_string(n % k) + s;
            n /= k;
        }

        return s;
    }

    bool check(string &s)
    {
        int len = s.length() / 2;
        for (int i = 0; i < len; i++)
        {
            if (s[i] != s[s.length() - i - 1])
                return false;
        }

        return true;
    }

public:
    long long kMirror(int k, int n)
    {
        int len = 1;
        int s = 0;
        int e = 1;
        long long sum = 0;
        while (n > 0)
        {
            for (int i = s; i < e; i++)
            {
                if (n <= 0)
                    break;
                long long f = 0;
                long long b = 0;
                if (i != 0)
                {
                    f = i;
                    int tmp = i;
                    while (tmp)
                    {
                        b *= 10;
                        b += tmp % 10;
                        tmp /= 10;
                    }
                }

                int ns = 1;
                int ne = 2;
                int lim = 1;
                if (len % 2)
                    lim *= 10;

                for (int j = 0; j < lim; j++)
                {
                    if (i == 0 && j == 0)
                        continue;
                    if (n <= 0)
                        break;
                    long long s = 0;
                    s += f * pow(10, len / 2);
                    if (len % 2)
                    {
                        s *= 10;
                        s += j * pow(10, len / 2);
                    }
                    s += b;

                    string converted = convert(s, k);

                    if (check(converted))
                    {
                        n--;
                        sum += s;
                    }
                }
            }

            if (len % 2)
            {
                s = e;
                e *= 10;
            }

            len++;
        }

        return sum;
    }
};
