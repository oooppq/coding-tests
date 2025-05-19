/*
조금 애를 먹긴 했다...
heap으로 푸는게 정석이긴 함
*/

/*
class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        unordered_map<char, int> freq;
        for (char ch : s)
        {
            freq[ch]++;
        }

        priority_queue<char> maxHeap;
        for (auto &[ch, count] : freq)
        {
            maxHeap.push(ch);
        }

        string result;

        while (!maxHeap.empty())
        {
            char ch = maxHeap.top();
            maxHeap.pop();
            int count = freq[ch];

            int use = min(count, repeatLimit);
            result.append(use, ch);

            freq[ch] -= use;

            if (freq[ch] > 0 && !maxHeap.empty())
            {
                char nextCh = maxHeap.top();
                maxHeap.pop();

                result.push_back(nextCh);
                freq[nextCh]--;

                if (freq[nextCh] > 0)
                {
                    maxHeap.push(nextCh);
                }

                maxHeap.push(ch);
            }
        }

        return result;
    }
};
*/

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        int n = s.length();
        struct
        {
            bool operator()(char l, char r) { return l > r; }
        } compare;

        sort(s.begin(), s.end(), compare);

        char prev = '0';
        int count = 1;
        int j = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == prev)
                count++;
            else
                count = 1;

            if (count > repeatLimit)
            {
                if (j < i)
                    j = i + 1;
                for (; j < n; j++)
                {
                    if (s[j] != s[i])
                    {
                        char tmp = s[i];
                        s[i] = s[j];
                        s[j] = tmp;
                        if (j + 1 < n)
                            j++;
                        break;
                    }
                }
                if (j >= n)
                {
                    while (j-- > i)
                        s.pop_back();
                    break;
                }
            }
            prev = s[i];
        }
        return s;
    }
};