class Solution {
public:
    using ll = long long;

    ll Count(vector<int>& coins, ll mid) {
        int n = coins.size();
        ll ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            ll lcm = 1;
            int order = 0;
            bool valid = true;

            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {
                    order++;

                    ll g = gcd(lcm, (ll)coins[j]);
                    lcm = lcm / g * coins[j];

                    if (lcm > mid) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            if (order % 2 == 1)
                ans += mid / lcm;
            else
                ans -= mid / lcm;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        ll l = 1;
        ll r = (ll)(*max_element(coins.begin(), coins.end())) * k;

        while (l < r) {
            ll mid = l + (r - l) / 2;

            if (Count(coins, mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};