/*
풀긴 풀었다.
leetcode/135.cpp의 접근방식과 비슷하게
양쪽에서 비교하는 방식으로 풀었다.
정답은
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int water = 0;

        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
            } else {
                right--;
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
            }
        }

        return water;
    }
};
이거긴 한데,
사실상 같은 접근이라고 보면 된다.
이게 더 깔끔하긴 한데,
직관적인 이해는 내 코드가 낫지 않나... 싶다.
일단 이렇게 아이디어를 짜놓고, 챗지피티한테 이걸 더 간단히 하는 방법 같은걸
물어보면 되지 않으려나 싶음.
*/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        int n = height.size();
        int prev = 0;
        int cumm = 0;
        for (int i = 0; i < n; i++)
        {
            if (prev > height[i])
            {
                cumm += prev - height[i];
            }
            else
            {
                prev = height[i];
                ans += cumm;
                cumm = 0;
            }
        }

        prev = 0;
        cumm = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (prev >= height[i])
            {
                cumm += prev - height[i];
            }
            else
            {
                prev = height[i];
                ans += cumm;
                cumm = 0;
            }
        }

        return ans;
    }
};