/*
걍 개 쳐 어려운 문제...
다시 풀어도 못 풀 것 같다.
dp를 사용해야 한다. 그냥 재귀하는거랑 아이디어는 같은데,
시간복잡도가 차이가 크게 난다.
접근조차 못했던 문제.
심지어 dp도 그냥 dp가 아니고, dp에 backtracking까지 하니까 답도 안나오게 어렵다.
꼬옥 다시풀어보자.
*/

// #include <queue>

// class Solution {
// public:
//     string shortestCommonSupersequence(string str1, string str2) {
//         int n = str1.size();
//         int m = str2.size();
//         string ret;

//         unordered_map<char, queue<int>> um;

//         for(int i = 0; i < n; i++) {
//             um[str1[i]].push(i);
//         }

//         int i = 0;
//         for(char& c : str2) {
//             while(!um[c].empty() && um[c].front() < i) um[c].pop();
//             if(!um[c].empty()) {
//                 int ni = um[c].front() + 1;
//                 ret += str1.substr(i, ni - i);
//                 um[c].pop();
//                 i = ni;
//             } else {
//                 ret.push_back(c);
//             }
//         }
//         if(i < n)
//             ret += str1.substr(i);

//         um.clear();

//         for(int i = 0; i < m; i++) {
//             um[str2[i]].push(i);
//         }

//         i = 0;
//         string ret2;
//         for(char& c : str1) {
//             while(!um[c].empty() && um[c].front() < i) um[c].pop();
//             if(!um[c].empty()) {
//                 int ni = um[c].front() + 1;
//                 ret2 += str2.substr(i, ni - i);
//                 um[c].pop();
//                 i = ni;
//             } else {
//                 ret2.push_back(c);
//             }
//         }
//         if(i < m)
//             ret2 += str2.substr(i);

//         return ret.length() < ret2.length() ? ret : ret2;
//     }
// };

// class Solution {
// public:
//     string shortestCommonSupersequence(string str1, string str2) {
//         // Base case: both strings are empty
//         if (str1.empty() && str2.empty()) {
//             return "";
//         }

//         // Base case: one string is empty, append the other string
//         if (str1.empty()) {
//             return str2;
//         }

//         if (str2.empty()) {
//             return str1;
//         }

//         // If the first characters match, include it in the supersequence
//         if (str1[0] == str2[0]) {
//             return str1[0] +
//                    shortestCommonSupersequence(str1.substr(1), str2.substr(1));
//         } else {
//             // Try both options: picking from str1 or str2, and choose the
//             // shorter one
//             string pickStr1 =
//                 str1[0] + shortestCommonSupersequence(str1.substr(1), str2);
//             string pickStr2 =
//                 str2[0] + shortestCommonSupersequence(str1, str2.substr(1));

//             return (pickStr1.length() < pickStr2.length()) ? pickStr1
//                                                            : pickStr2;
//         }
//     }
// };

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        string ret;
        int n = str1.length();
        int m = str2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }

        while (n > 0 && m > 0)
        {
            if (str1[n - 1] == str2[m - 1])
            {
                ret.push_back(str1[n - 1]);
                n--;
                m--;
            }
            else
            {
                if (dp[n - 1][m] < dp[n][m - 1])
                {
                    ret.push_back(str1[n - 1]);
                    n--;
                }
                else
                {
                    ret.push_back(str2[m - 1]);
                    m--;
                }
            }
        }

        while (n > 0)
        {
            ret.push_back(str1[n - 1]);
            n--;
        }

        while (m > 0)
        {
            ret.push_back(str2[m - 1]);
            m--;
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};