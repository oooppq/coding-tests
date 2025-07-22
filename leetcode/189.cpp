/*
그냥 알고리즘적으로 풀면 내 풀이고, 이를 c++적으로 풀면

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> newNums(nums.end() - k, nums.end());
        newNums.insert(newNums.end(), nums.begin(), nums.end() - k);
        copy(newNums.begin(), newNums.end(), nums.begin());
    }
};

이렇게 풀 수 있다.
 */
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        vector<int> newNums;
        for (int i = 0; i < nums.size(); i++)
        {
            newNums.push_back(nums[(i + nums.size() - k) % nums.size()]);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = newNums[i];
        }
    }
};