/*
못품. 개어려움.
sorting이 필요한 것 까진 이해했는데,
바이너리 서치가 그정도로 시간을 많이 줄여주는지 감을 못잡았다.
다시 풀자!!!
*/

class Solution
{
public:
    // Find the number of valid pairs by greedy approach
    int countValidPairs(vector<int> &nums, int threshold)
    {
        int index = 0, count = 0;
        while (index < nums.size() - 1)
        {
            // If a valid pair is found, skip both numbers.
            if (nums[index + 1] - nums[index] <= threshold)
            {
                count++;
                index++;
            }
            index++;
        }
        return count;
    }

    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = nums[n - 1] - nums[0];

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            // If there are enough pairs, look for a smaller threshold.
            // Otherwise, look for a larger threshold.
            if (countValidPairs(nums, mid) >= p)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};

// class Solution {
// public:
//     int minimizeMax(vector<int>& nums, int p) {
//         sort(nums.begin(), nums.end());
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for(int i = 1; i < nums.size(); i++)
//         {
//             pq.push(abs(nums[i] - nums[i - 1]));
//         }
//         int ret = 0;
//         while(p-- > 0)
//         {
//             ret = pq.top();
//             pq.pop();
//         }

//         if(p > 0) ret = 0;
//         return ret;
//     }
// };