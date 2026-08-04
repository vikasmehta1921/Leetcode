class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> PrefixSum(n, 0);
        PrefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            PrefixSum[i] = PrefixSum[i - 1] + nums[i];
        }
        unordered_map<int, int> m; // PS , freq
        for (int j = 0; j < n; j++) {
            if (PrefixSum[j] == k) {
                count++; // first ans if target is found in subarray
            }
            int val = PrefixSum[j] -
                      k; // checking value that find prefix dum and made
            if (m.find(val) != m.end()) {
                count += m[val];
            }
            if (m.find(PrefixSum[j]) == m.end()) {
                m[PrefixSum[j]] = 0; // intalize freq with zero
            }
            m[PrefixSum[j]]++; // increase feq with 1
        }
        return count;
    }
};