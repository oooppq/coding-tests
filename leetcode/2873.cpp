/*
쉬운문제. 근데 O(n3)으로 풀었는데, O(n)도 가능한 문제...
수가 커지면 아래의 풀이를 생각해내야한다.
*/

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        long long ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    long long tmp = ((long long)nums[i] - (long long)nums[j]) * (long long)nums[k];
                    ret = ret > tmp ? ret : tmp;
                }
            }
        }

        return ret;
    }
};

// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         int n = nums.size();
//         long long res = 0, imax = 0, dmax = 0;
//         for (int k = 0; k < n; k++) {
//             res = max(res, dmax * nums[k]);
//             dmax = max(dmax, imax - nums[k]);
//             imax = max(imax, static_cast<long long>(nums[k]));
//         }
//         return res;
//     }
// };