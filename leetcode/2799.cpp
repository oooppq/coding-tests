/*
O(n)으로 풀 수도 있는건데, 조건 보고 걍 귀찮아서 O(n^2)으로 풀었음.
어렵지 않은 문제긴 했는데,
if (us.count(nums[j]) == 0)
                    break;

이 부분이 좀 하이라이트 느낌.
*/

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int ret = 0;
        int n = nums.size();
        unordered_set<int> us(nums.begin(), nums.end());
        // for(int &num : nums) us.insert(num);

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> tmp;
            for (int j = i; j < n; j++)
            {
                if (us.count(nums[j]) == 0)
                    break;
                tmp.insert(nums[j]);

                if (us.size() == tmp.size())
                    ret++;
            }
        }

        return ret;
    }
};