#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt0 = 0, a = 0;

        for (int num : nums) {
            if (num == 0) {
                a++;
                cnt0 += a;
            } else {
                a = 0;
            }
        }

        return cnt0;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {0, 0, 1, 0, 0, 0};  // Example input

    long long result = sol.zeroFilledSubarray(nums);

    cout << "Total number of zero-filled subarrays: " << result << endl;

    return 0;
}
