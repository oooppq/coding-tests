/*
merge sort로 푸는 문제긴 한데...
걍 sort로 풀어버렸다.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n - 1;
        m--;
        n--;

        while(n >= 0)
        {
            if(m >= 0 && nums1[m] > nums2[n])
            {
                nums1[i] = nums1[m];
                m--;
            }
            else
            {
                nums1[i] = nums2[n];
                n--;
            }
            i--;
        }
    }
};
사실 이게 정석.
근데, sort는 답을 보면 쉬운데 막상 구현 아이디어가 생각 안나는 경우가 많다.
*/

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = m; i < nums1.size(); i++)
            nums1[i] = nums2[i - m];
        sort(nums1.begin(), nums1.end());
    }
};