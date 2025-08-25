#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            if (count > 1) return false;
        }

        return true;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 4, 5, 1, 2};  // This is a valid rotation of [1,2,3,4,5]

    bool result = sol.check(nums);

    cout << "Is rotated sorted array? " << (result ? "Yes" : "No") << endl;

    return 0;
}
