class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int mx = INT_MIN;
        for (int num : nums) {
            mx = max(num, mx);
            int ans = gcd(num, mx);
            prefixGcd.push_back(ans);
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        int left = 0;
        int right = prefixGcd.size() - 1;
        long long sum = 0;
        while (left < right) {
            int check = gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
            sum = check + sum;
        }
        return sum;
    }
};