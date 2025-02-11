/*
진짜 바보같이 풀었다. 어차피, s.length와 part.length가 1000이하이므로
시간복잡도를 크게 신경쓸 필요가 없었다.그냥 find로 substring을 계속 찾기만 하면된다.
찾는 것은 O(n)이고, 찾을 때마다 m만큼 줄테니까 최대 O(n * n / m) 일 것이다.
내가 시도하려는 방법은 kmp 비스무리한건데, 일단 어려워서 구현을 못했고,
stack을 이용해서 푸는 것도 그냥 매 포지션마다 substring 여부를 체크해보는 식으로 쉽게 구현할 수 있다.
이거도 해봤자 O(n * m) 이다.
*/

// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         while (s.find(part) != string::npos) {
//             size_t part_start_index = s.find(part);

//             s = s.substr(0, part_start_index) +
//                 s.substr(part_start_index + part.length());
//         }

//         return s;
//     }
// };

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        string ret;
        int n = s.size();
        int m = part.size();

        for (int i = 0; i < n; i++)
        {
            ret.push_back(s[i]);

            if (ret.size() >= m)
            {
                bool flag = true;
                for (int j = 0; j < m; j++)
                {
                    int k = ret.size() - m + j;
                    if (ret[k] != part[j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    for (int j = 0; j < m; j++)
                        ret.pop_back();
                }
            }
        }

        return ret;
    }
};