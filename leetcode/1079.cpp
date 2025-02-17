/*
그냥 모든 조합 다돌면서 중복만 제거해주면 되는 문젠데, 처음에는 아래 주석과 같이
괜히 빈자리를 원소로 넣어서 풀려고 했다. 하나 안 사실은, 한 문제 푸는 데에 시간초과가 안나더라도
누적으로 시간이 많이 걸리면 시간초과 fail 뜬다는 것... 너무 바보 같은 접근이었다.
그리고, map이 있듯, set도 있다... 바보
*/

class Solution
{
    int n;
    string t;
    unordered_set<string> um;
    vector<pair<string, int>> st;

public:
    int numTilePossibilities(string tiles)
    {
        n = tiles.length();
        string t = tiles;
        vector<bool> vis(n);

        r(tiles, "", vis);

        return um.size() - 1;
    }

    void r(string &tiles, string s, vector<bool> &vis)
    {
        // cout << s << endl;
        um.insert(s);

        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;
            vis[i] = true;
            r(tiles, s + tiles[i], vis);
            vis[i] = false;
        }
    }
};

/*
class Solution {
    int n;
    string t;
    unordered_map<string, int> um;
    vector<pair<string, int>> st;
public:
    int numTilePossibilities(string tiles) {
        n = tiles.length();
        t = tiles;
        for(int i = 0; i < n; i++) t += ' ';
        vector<bool> vis(n * 2);
        int ret = 0;
        r("", 0, vis);

        for(auto e : um) ret++;
        return ret;
    }

    void r(string s, int now, vector<bool> &vis) {
        if(now >= n) {
            // cout << s << endl;
            if(s != "") um[s]++;
            return;
        }

        for(int i = 0; i < 2 * n; i++) {
            if(vis[i]) continue;
            vis[i] = true;
            string ns = s;
            if(t[i] != ' ') ns += t[i];
            r(ns, now + 1, vis);
            vis[i] = false;
        }

    }
};
*/