/*
어차피 arr의 길이가 1000이하이므로, O(n^3)의 시간복잡도로 풀어도 충분하다.
아래 주석처럼 dp로 푸는게 더 깔끔하긴 하다. 나는 dp에 참 약하다..
*/

// class Solution {
//     public:
//         int lenLongestFibSubseq(vector<int>& arr) {
//             int maxLen = 0;
//             // dp[prev][curr] stores length of Fibonacci sequence ending at indexes
//             // prev,curr
//             vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

//             // Map each value to its index for O(1) lookup
//             unordered_map<int, int> valToIdx;

//             // Fill dp array
//             for (int curr = 0; curr < arr.size(); curr++) {
//                 valToIdx[arr[curr]] = curr;

//                 for (int prev = 0; prev < curr; prev++) {
//                     // Find if there exists a previous number to form Fibonacci
//                     // sequence
//                     int diff = arr[curr] - arr[prev];
//                     int prevIdx = (valToIdx.find(diff) != valToIdx.end())
//                                       ? valToIdx[diff]
//                                       : -1;

//                     // Update dp if valid Fibonacci sequence possible
//                     // diff < arr[prev] ensures strictly increasing sequence
//                     if (diff < arr[prev] && prevIdx >= 0) {
//                         dp[prev][curr] = dp[prevIdx][prev] + 1;
//                     } else {
//                         dp[prev][curr] = 2;
//                     }

//                     maxLen = max(maxLen, dp[prev][curr]);
//                 }
//             }

//             // Return 0 if no sequence of length > 2 found
//             return maxLen > 2 ? maxLen : 0;
//         }
//     };

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int ret = 0;
        int n = arr.size();
        unordered_set<int> us;

        for (int &num : arr)
            us.insert(num);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int pp = arr[i];
                int p = arr[j];
                // cout << "i: " << i << " j: " << j << endl;
                int tmp = 2;
                while (us.count(pp + p) > 0)
                {
                    int newp = pp + p;
                    pp = p;
                    p = newp;
                    tmp++;
                }
                if (tmp == 2)
                    tmp = 0;
                ret = ret > tmp ? ret : tmp;
            }
        }

        return ret;
    }
};