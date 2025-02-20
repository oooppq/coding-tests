/*
그냥 permutation으로 풀면 되는 문제
밑에는 되게 신기한 풀이다. stoi가 base를 2진수로 할 수 있다는 것도 처음 알았고,
bitset으로 만들어버리는 함수도 있는걸 처음... 은 아니고 언젠가 봤던거같은데 무튼 신기
*/

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        unordered_set<int> integers;
        for (string num : nums)
        {
            cout << stoi(num, 0, 2) << endl;
            integers.insert(stoi(num, 0, 2));
        }

        int n = nums.size();
        for (int num = 0; num <= n; num++)
        {
            if (integers.find(num) == integers.end())
            {
                string ans = bitset<16>(num).to_string();
                std::cout << ans;
                return ans.substr(16 - n);
            }
        }

        return "";
    }
};

class Solution
{
    vector<string> bins;

public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums.size();

        r("", 0, n);
        for (string num : bins)
        {
            bool flag = true;
            for (string s : nums)
            {
                if (num == s)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return num;
        }
        // for(int i = 0; i < 16; i++) n *= 2;
        // cout << n << endl;
        // int tmp = 0;
        // for(int i = 0; i < n; i++) {
        //     tmp += i;
        // }

        return "";
    }

    void r(string s, int i, int n)
    {
        if (i >= n)
        {
            bins.push_back(s);
            return;
        }

        r(s + "0", i + 1, n);
        r(s + "1", i + 1, n);
    }
};