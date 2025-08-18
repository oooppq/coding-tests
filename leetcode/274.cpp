/*
sort로 풀면 접근이 쉬움.
근데 그냥 O(n)으로도 풀 수 있음.
paper의 수를 기준으로 dp를 하면 되는 느낌.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int papers = citations.size();
        vector<int> citationBuckets(papers + 1, 0);

        for (int citation : citations) {
            citationBuckets[min(citation, papers)]++;
            cout <<
        }

        int cumulativePapers = 0;
        for (int hIndex = papers; hIndex >= 0; hIndex--) {
            cumulativePapers += citationBuckets[hIndex];
            if (cumulativePapers >= hIndex) {
                return hIndex;
            }
        }
        return 0;
    }
};
*/

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        sort(citations.begin(), citations.end());

        int hIdx = 0;
        for (int i = 0; i < n; i++)
        {
            hIdx = max(hIdx, min(n - i, citations[i]));
        }

        return hIdx;
    }
};