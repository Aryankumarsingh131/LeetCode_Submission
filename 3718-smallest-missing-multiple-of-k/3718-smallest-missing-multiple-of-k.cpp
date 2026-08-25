class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> mult;

        for (int num : nums) {
            mult.insert(num);
        }

        int n = k;

        while (true) {
            if (mult.count(n)) {
                n += k;
            } else {
                return n;
            }
        }
    }
};