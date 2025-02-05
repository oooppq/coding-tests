/*
간단하게 풀긴 했는데, 풀이 방법이 좀 허술하긴 하다.
좀 더 프로그래밍적으로 풀려면, 각 알파벳의 빈도수를 기록해서, 서로 다른지 파악하는게 더 좋은 방법인 듯 하다.
*/

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int count = 0;
        int two[2];
        int n = s1.size();

        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                if (count >= 2)
                    return false;
                two[count++] = i;
            }
        }

        if (count == 0)
            return true;
        if (count == 1)
            return false;

        if (s1[two[0]] == s2[two[1]] && s1[two[1]] == s2[two[0]])
            return true;

        return false;
    }
};