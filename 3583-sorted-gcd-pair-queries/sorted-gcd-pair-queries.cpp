class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // Frequency of each value
        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // Count numbers divisible by each d
        vector<int> divisibleCount(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            for (int multiple = d; multiple <= mx; multiple += d) {
                divisibleCount[d] += freq[multiple];
            }
        }

        // Number of pairs divisible by d
        vector<long long> exact(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            long long cnt = divisibleCount[d];
            exact[d] = cnt * (cnt - 1) / 2;
        }

        // Inclusion-Exclusion:
        // exact[d] = pairs with gcd exactly d
        for (int d = mx; d >= 1; d--) {
            for (int multiple = 2 * d; multiple <= mx; multiple += d) {
                exact[d] -= exact[multiple];
            }
        }

        // Prefix count of gcd values
        vector<long long> prefix(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            prefix[d] = prefix[d - 1] + exact[d];
        }

        // Answer queries using binary search
        vector<int> ans;
        for (long long q : queries) {
            int gcdValue = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(gcdValue);
        }

        return ans;
    }
};