/*
아이디어 자체는 금방 떠올랐다.
j - i != nums[j] - nums[i]는 결국 i - nums[i] != j - nums[j]와 같다. 따라서, i - nums[i]를 map으로 저장해두면,
good pairs를 찾을 수 있다.
처음에는 전체 pairs에서 good pairs들을 빼는 방식으로 했는데, 수가 너무 커서 runtime error가 났다.
그래서 답을 봤는데, nC2 라는 특성을 이용하여 nums의 개수만큼 iter를 돌면서 하나 추가될 때마다 추가되는 pair의 수에서 good pair의 수를 빼주는 방식으로 했다.
[4,1,3,3] 이라면,
i = 0 -> 0 - 0
i = 1 -> 1 - 0
i = 2 -> 2 - 0
i = 3 -> 3 - 1 (1 - 3 == nums[1] - nums[3])
이렇게 되는 것이다.
또하나 배웠다.

그리고, 오버플로우가 발생했던 이유는 n이 int이기 때문에 n * (n - 1)은 int로 계산된 후 long long으로 변환되기 때문이다.
n을 long long으로 바꿔주거나, (long long)n * (n - 1)로 해주면 된다. 바보같은 실수..
*/

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        int n = nums.size();
        long long ret = 0;
        unordered_map<long long, long long> um;

        for (int i = 0; i < n; i++)
        {
            long long diff = i - nums[i];
            ret += i - um[diff]++;
        }

        return ret;
    }
};

// class Solution
// {
// public:
//     long long countBadPairs(vector<int> &nums)
//     {
//         int n = nums.size();
//         long long ret = n * (n - 1) / 2;
//         unordered_map<long long, long long> um;

//         for (int i = 0; i < n; i++)
//         {
//             long long diff = i - nums[i];
//             um[diff]++;
//         }

//         for (auto e : um)
//         {
//             ret -= e.second * (e.second - 1) / 2;
//         }

//         return ret;
//     }
// };