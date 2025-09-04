/*
기본적인 슬라이딩 윈도우 문제.
min값을 매 조합마다 업데이트하는게 핵심
현재의 r에 대해 최소 subarray 길이를 항상 구하게 됨
while 조건에서 l <= r은 필요 없음.
어차피 l == r이 되면 curr == 0이 되고, target은 최소 1이기 떄문.
이런 디테일이 뭔가 중요하다.
*/

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ret = 100001;
        int curr = 0;

        for (; r < n; r++)
        {
            curr += nums[r];
            while (l <= r && curr >= target)
            {
                // cout << l << " " << r << " " << curr << endl;
                ret = min(ret, r - l + 1);
                curr -= nums[l++];
            }
        }
        if (ret > 100000)
            ret = 0;
        return ret;
    }
};