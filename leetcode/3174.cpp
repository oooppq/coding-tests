/*
easy라서 되게 쉽게 풀었는데, 한 가지 알게된 것은 string도 vector처럼 push_back, pop_back을 사용할 수 있다는 것이다.
*/

class Solution
{
public:
    string clearDigits(string s)
    {
        string ret;
        for (auto c : s)
        {
            if (c >= '0' && c <= '9')
                ret.pop_back();
            else
                ret.push_back(c);
        }
        return ret;

        // vector<char> ret;
        // for(auto c : s) {
        //     if(c >= '0' && c <= '9') ret.pop_back();
        //     else ret.push_back(c);
        // }

        // string tmp;
        // tmp.resize(ret.size());

        // for(int  i = 0; i < ret.size(); i++) {
        //     tmp[i] = ret[i];
        // }

        // return tmp;
    }
};