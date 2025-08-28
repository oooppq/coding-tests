/*
hard긴 한데, 이런 문제를 hard로 볼 수 있나 싶다.
사실상 그냥 구현 문제.
string(toAdd, ' ') 이런거 쓰면 더 편하긴 하겠다.
*/

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int cumm = 0;
        queue<string> q;
        vector<string> ans;
        for (auto word : words)
        {
            if (cumm + word.length() > maxWidth)
            {
                int qCnt = q.size();
                string justified = "";
                if (qCnt == 1)
                {
                    justified += q.front();
                    for (int i = 0; i < maxWidth - q.front().length(); i++)
                        justified += " ";
                    q.pop();
                }
                else
                {
                    int toDivide = maxWidth - cumm + qCnt;
                    int ea = toDivide / (qCnt - 1);
                    int left = toDivide % (qCnt - 1);

                    int toAdd = 0;
                    while (!q.empty())
                    {
                        for (int i = 0; i < toAdd; i++)
                            justified += " ";
                        justified += q.front();
                        q.pop();
                        toAdd = ea;
                        if (left > 0)
                        {
                            toAdd += 1;
                            left--;
                        }
                    }
                }
                ans.push_back(justified);
                cumm = 0;
            }
            q.push(word);
            cumm += word.length() + 1;
        }
        string justified = "";
        while (!q.empty())
        {
            justified += q.front();
            if (justified.length() < maxWidth)
                justified += " ";
            q.pop();
        }

        while (justified.length() < maxWidth)
            justified += " ";
        ans.push_back(justified);

        return ans;
    }
};