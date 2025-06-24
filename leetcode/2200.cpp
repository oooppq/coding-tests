/*
걍 쉬운문제.
더 쉽게 풀 수 있는데, 문제를 좀 오해해서 좀 귀찮게 풀었음.
*/

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        unordered_set<int> us;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == key)
            {
                int s = 0 > i - k ? 0 : i - k;
                int e = n < i + k + 1 ? n : i + k + 1;
                for (int j = s; j < e; j++)
                    us.insert(j);
            }
        }
        vector<int> ret;
        for (auto idx : us)
            ret.push_back(idx);
        sort(ret.begin(), ret.end());

        return ret;
    }
};