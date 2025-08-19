/*
힌트를 봤다.
양 옆보다 높으면 +1이어야 한다는 조건이었는데,
그럼 순방향 역방향으로 이를 두 번 따져보면 된다.
이 때, max를 활용하는 것이 포인트.
아이디어만 떠올리면 되게 쉬운데, 떠올리기가 어려움.
걍 양 방향으로 이동하면서 지금이 이전보다 더 큰지만 따지면 끝.
*/

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        bool flag = false;
        int n = ratings.size();
        vector<int> candy(n, 1);
        int prev = 0;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i - 1] < ratings[i])
                candy[i] = candy[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i + 1] < ratings[i])
                candy[i] = max(candy[i], candy[i + 1] + 1);
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += candy[i];

        return sum;
    }
};