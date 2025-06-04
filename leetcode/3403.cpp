/*
풀긴했는데, 까다로운 문제긴 하다.
뭔가 될까 싶은 생각으로 하긴 함...
n이 5x10^3이기 때문에, 그냥 O(n^2)으로 풀었음.
*/

class Solution
{
public:
    string answerString(string word, int numFriends)
    {
        if (numFriends == 1)
            return word;
        int maxChar = word[0];
        int n = word.length();

        for (char &c : word)
        {
            if (maxChar < c)
                maxChar = c;
        }

        vector<int> maxs;

        for (int i = 0; i < n; i++)
        {
            if (word[i] == maxChar)
                maxs.push_back(i);
        }

        priority_queue<string> pq;

        for (int &idx : maxs)
        {
            int lim = n;
            if (idx < numFriends)
            {
                lim -= numFriends - 1;
            }
            pq.push(word.substr(idx, lim));
        }

        return pq.top();
    }
};