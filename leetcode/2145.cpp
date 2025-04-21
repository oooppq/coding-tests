/*
min과 max값을 초기값을 어떻게 설정해야 할까 싶었는데,
이후에 min, max를 0으로 짜르는 거였으면 걍 첨부터 0으로 설정해도 됐다.
밑에 maxN, minN, diff 어쩌구 하는 식들도 이쁘게 포장하면 주석과 같은 풀이가 완성된다.
*/

/*
class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        int minN = 0;
        int maxN = 0;

        int cumm = 0;
        for (int &num : differences)
        {
            cumm += num;
            minN = min(minN, cumm);
            maxN = max(maxN, cumm);

            if (maxN - minN > upper - lower)
                return 0;
        }

        return (upper - lower) - (maxN - minN) + 1;
    }
};
*/

class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        long long minN = upper - lower;
        long long maxN = lower - upper;

        long long cumm = 0;
        for (int &num : differences)
        {
            cumm += num;
            minN = min(minN, cumm);
            maxN = max(maxN, cumm);
        }

        if (minN > 0)
            minN = 0;
        if (maxN < 0)
            maxN = 0;
        long long diff = lower - minN;
        diff = maxN + diff;
        if (diff > upper)
            return 0;

        // cout << minN << " " << maxN << endl;

        return upper - diff + 1;
    }
};