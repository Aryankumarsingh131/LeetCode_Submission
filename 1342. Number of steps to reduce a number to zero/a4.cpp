#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0;
        while (num > 0) {
            if (num % 2 == 0) {
                num /= 2;   
            } else {
                num -= 1;   
            }
            cnt++;
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    int num;
    cout << "Enter a number: ";
    cin >> num;

    int steps = sol.numberOfSteps(num);

    cout << "Number of steps to reduce " << num << " to zero: " << steps << endl;

    return 0;
}
