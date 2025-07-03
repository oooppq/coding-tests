/*
쉬운 문젠데, __lg라는걸 처음 알았다.
이런거 알아두면 유용할듯.
*/

class Solution
{
public:
    char kthCharacter(int k)
    {
        char ret = 'a';

        int count = 0;
        while (k != 1)
        {
            // int toSub = 1;
            // while(toSub * 2 < k) toSub *= 2;
            int toSub = __lg(k);
            if ((1 << toSub) == k)
                toSub--;

            k -= (1 << toSub);
            count++;
        }

        ret += count;

        return ret;
    }
};