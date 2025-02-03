/*
쉽게 풀었다. 2열 고정이기 때문에 1열에서 2열로 어느 행에서 이동하느냐에 따라 최소값이 달라진다.
행의 길이만큼 반복하면서 비교하면 되는데,
    t -= grid[0][i];
    long long int m = t > b ? t : b;
    b += grid[1][i];
매 번 이렇게 t와 b 사이에서 최댓값을 구하는게 포인트다.
해당 열을 확인할 때에는 b에 아직 더하지 않은 상태가 되어야 하기 때문..
물론, 이렇게 안하고 코드를 추가적으로 더 써서 해도 되는데 이게 젤 깔끔한 듯 하다.
LONG_LONG_MAX를 배운건 덤.
*/
class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        long long int min = 0;
        int n = grid[0].size();
        vector<int> a(n);
        long long int t = 0;
        long long int b = 0;
        for (int i = 0; i < n; i++)
        {
            t += grid[0][i];
        }
        min = LONG_LONG_MAX;
        for (int i = 0; i < n; i++)
        {
            t -= grid[0][i];
            long long int m = t > b ? t : b;
            b += grid[1][i];

            if (m < min)
                min = m;
        }

        return min;
    }
};