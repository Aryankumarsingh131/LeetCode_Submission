class Solution {
public:
    string ans = "";

    bool solve(string &cur, vector<int>& cnt, string &t, int i, bool big, int n) {
        if(i == n / 2) {
            string right = cur;
            reverse(right.begin(), right.end());

            string mid = "";
            for(int j = 0; j < 26; j++) {
                if(cnt[j] % 2) {
                    mid += char('a' + j);
                    break;
                }
            }

            string res = cur + mid + right;

            if(res > t) {
                ans = res;
                return true;
            }
            return false;
        }

        for(char c = 'a'; c <= 'z'; c++) {
            if(cnt[c-'a'] < 2 || (!big && c < t[i]))
                continue;

            cur += c;
            cnt[c-'a'] -= 2;

            if(solve(cur, cnt, t, i + 1, big || c > t[i], n))
                return true;

            cur.pop_back();
            cnt[c-'a'] += 2;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        vector<int> cnt(26);

        for(char c : s)
            cnt[c-'a']++;

        int odd = 0;
        for(int x : cnt)
            odd += x % 2;

        if(odd > 1)
            return "";

        string cur;
        solve(cur, cnt, target, 0, false, s.size());

        return ans;
    }
};