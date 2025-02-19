/*
틀렸는데, 솔직히 잘 모르겠다. dp다.
뒤에서부터 dp 테이블을 채워나가는데, 앞에서부터 채워나가도 되지만, 0보다 작은 인덱스를 조건처리하는게 번거로워서 뒤에서부터 하는듯 하다.
이 인덱스에서 딕셔너리에 있는 놈을 포함할지 안포함할지를 dp테이블을 통해 결정해가면서, 해당 인덱스의 dp값은 항상 최솟값이 되도록 유지하는 것이다.
꼭 다시풀어보자진짜 아오
*/

class Solution
{
public:
    int minExtraChar(string s, vector<string> dictionary)
    {
        int n = s.length();
        unordered_set<string> dictionarySet(dictionary.begin(), dictionary.end());
        vector<int> dp(n + 1, 0);

        for (int start = n - 1; start >= 0; start--)
        {
            dp[start] = dp[start + 1] + 1;
            cout << "start: " << start << endl;
            for (int end = start; end < n; end++)
            {
                auto curr = s.substr(start, end - start + 1);
                cout << curr << " " << dictionarySet.count(curr) << endl;
                if (dictionarySet.count(curr))
                {
                    dp[start] = min(dp[start], dp[end + 1]);
                }
            }
            cout << "dp:" << dp[start] << endl;
        }

        return dp[0];
    }
};