/*
좀 직관적으로 풀어서 딱 이해하진 않았는데,
양쪽에서부터 줄여가면 되지 않을까 싶어서 이렇게 풀었다.
*/

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ret = 0;
        int n = height.size();
        int s = 0;
        int e = n - 1;

        while (s < e)
        {
            int h = min(height[s], height[e]);
            int now = h * (e - s);
            ret = ret > now ? ret : now;

            if (height[s] < height[e])
                s++;
            else
                e--;
        }

        return ret;
    }
};