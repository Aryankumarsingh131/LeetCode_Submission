#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }

        return maxProfit;
    }
};

int main() {
    Solution sol;
    
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    
    int profit = sol.maxProfit(prices);

    cout << "Maximum profit: " << profit << endl;

    return 0;
}
