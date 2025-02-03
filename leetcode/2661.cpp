/*
처음에는 누적합하고 탐색 같은 것을 사용해야 하는 줄 알고 엄청 시행착오를 겪었다.
단순히, 각각의 row와 column에 대해 count 해주면 그만인 쉬운 문제였다.
*/

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int ret = 0;
        int n = mat.size();
        int m = mat[0].size();
        // int idx = 0;
        vector<pair<int, int>> d(n * m + 1);
        vector<int> rowCount(n);
        vector<int> colCount(m);
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                d[mat[i][j]] = make_pair(i, j);
            }
        }
        for (auto &num : arr)
        {
            int i = d[num].first;
            int j = d[num].second;

            rowCount[i]++;
            colCount[j]++;

            if (rowCount[i] >= m || colCount[j] >= n)
                break;

            ret++;
        }
        return ret;
    }
};