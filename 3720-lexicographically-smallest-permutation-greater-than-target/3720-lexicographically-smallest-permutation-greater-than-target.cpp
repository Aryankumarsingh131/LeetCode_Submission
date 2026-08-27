class Solution {
public:
    string ans = "";

    bool solve(string &cur, vector<int>& cnt, string &t, int i, bool big) {
        if(i == t.size()) return big ? (ans = cur, true) : false;

        for(char c = 'a'; c <= 'z'; c++) {
            if(!cnt[c-'a'] || (!big && c < t[i])) continue;

            cur += c;
            cnt[c-'a']--;

            if(solve(cur, cnt, t, i+1, big || c > t[i])) return true;

            cur.pop_back();
            cnt[c-'a']++;
        }
        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26);
        for(char c : s) cnt[c-'a']++;

        string cur;
        solve(cur, cnt, target, 0, false);
        return ans;
    }
};