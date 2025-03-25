/*
leetcode/3169.cpp 와 같은 유형의 문제다.
주의해야 할 점은 2개의 선을 긋는게 아니고 3개를 긋는다는 생각으로 구현해야 한다는 것..
선 두 개 긋고 마지막 구역에 도형이 하나도 없으면 안된다.
즉, if(chk == 2 && t.first < n)일 때 true라고 하면, 마지막 구역에 도형이 하나도 없는 경우에도 true가 된다.
조건에 주의하자.
*/

class Solution
{
public:
    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        struct cmp
        {
            bool operator()(pair<int, int> a, pair<int, int> b)
            {
                if (a.first != b.first)
                    return a.first > b.first;
                return a.second < b.second;
            }
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> vpq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> hpq;

        for (auto &rec : rectangles)
        {
            hpq.push({rec[0], 0});
            hpq.push({rec[2], 1});
            vpq.push({rec[1], 0});
            vpq.push({rec[3], 1});
        }

        int cnt = 0;
        int chk = 0;
        while (!vpq.empty())
        {
            pair<int, int> t = vpq.top();
            vpq.pop();
            if (t.second == 0)
                cnt++;
            else
                cnt--;

            if (cnt == 0)
                chk++;
            if (chk == 3)
                return true;
        }

        cnt = 0;
        chk = 0;

        while (!hpq.empty())
        {
            pair<int, int> t = hpq.top();
            hpq.pop();
            if (t.second == 0)
                cnt++;
            else
                cnt--;

            if (cnt == 0)
                chk++;
            if (chk == 3)
                return true;
        }

        return false;
    }
};