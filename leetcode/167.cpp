/*
썩 어렵지 않은데, 이렇게 풀거면 범위에 유의할 것
*/

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> cnt(3001, 0);

        for (auto num : numbers)
            cnt[num + 1000]++;

        int i = 0;
        for (; i < numbers.size(); i++)
        {
            int now = numbers[i];
            cnt[now + 1000]--;

            if (cnt[target - now + 1000])
                break;

            cnt[now + 1000]++;
        }

        int j = i + 1;
        for (; j < numbers.size(); j++)
        {
            if (numbers[j] == (target - numbers[i]))
                break;
        }

        return {i + 1, j + 1};
    }
};