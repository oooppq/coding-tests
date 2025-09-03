/*
되게 까다로운 문젠데 어떻게 medium인가 싶다.
틀렸음 다시풀어야돼.
중복을 방지하는 부분이 매우 중요...
아이디어가 좀 어렵다.
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        const int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // i 중복 스킵
            if (nums[i] > 0)
                break; // 더 이상 합이 0이 될 수 없음

            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0)
                    ++l;
                else if (sum > 0)
                    --r;
                else
                {
                    res.push_back({nums[i], nums[l], nums[r]});

                    // l 중복 스킵
                    int lv = nums[l];
                    while (l < r && nums[l] == lv)
                        ++l;

                    // r 중복 스킵
                    int rv = nums[r];
                    while (l < r && nums[r] == rv)
                        --r;
                }
            }
        }
        return res;
    }
};