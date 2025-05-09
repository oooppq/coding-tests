/*
아이디어가 쪼끔 까다롭긴 한데, 어렵진 않은 문제.
걍 슬라이딩 윈도우다.
*/

class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        int ret = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int s = 0;
        for (int e = 0; e < n; e++)
        {
            while (s <= e && (nums[e] - nums[s] > k * 2))
                s++;
            ret = max(ret, e - s + 1);
        }

        return ret;
    }
};