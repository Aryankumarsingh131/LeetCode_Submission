class Solution {
public:
    bool sumGame(string num) {
        int prefix_sum = 0;
        int suffix_sum = 0;
        int cnt1 = 0, cnt2 = 0;

        int i = (num.size() - 1) / 2;
        int j = (num.size() + 1) / 2;

        while (i >= 0) {

            if (num[i] == '?') {
                cnt1++;
            } else {
                prefix_sum += num[i] - '0';
            }

            if (num[j] == '?') {
                cnt2++;
            } else {
                suffix_sum += num[j] - '0';
            }

            i--;
            j++;
        }

        if (2 * (prefix_sum - suffix_sum) != 9 * (cnt2 - cnt1)) {
            return true;
        }

        return false;
    }
};