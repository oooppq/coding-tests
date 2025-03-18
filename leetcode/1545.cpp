/*
살짝 아이디어가 필요하긴 한데 어렵진 않음. 재밌는 문제.
*/

class Solution
{
    char reverse(char n)
    {
        if (n == '1')
            return '0';
        else
            return '1';
    }

    char recur(int s, int e, int i)
    {
        int m = (s + e) / 2;
        if (m == 1)
            return '0';
        if (m == i)
            return '1';

        if (i < m)
            return recur(s, m - 1, i);
        else
            return reverse(recur(s, m - 1, 2 * m - i));
    }

public:
    char findKthBit(int n, int k)
    {
        int e = 1;
        for (int i = 1; i < n; i++)
            e = e * 2 + 1;
        return recur(1, e, k);
    }
};