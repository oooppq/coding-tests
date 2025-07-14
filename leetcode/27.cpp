/*
걍 쉬움.
주석처리한게 내가 짠건데, 문제상 굳이 sorting할 필욘 없음.
*/

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // if(nums[i] == val) nums[i] = 51;
            if (nums[i] != val)
            {
                nums[idx++] = nums[i];
            }
        }
        return idx;
        // sort(nums.begin(), nums.end());
        // int count = 0;
        // for(int num : nums)
        // {
        //     if(num > 50) break;
        //     count++;
        // }

        // return count;
    }
};