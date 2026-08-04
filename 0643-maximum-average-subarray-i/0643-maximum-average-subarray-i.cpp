class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0;
        double ans = INT_MIN;
        double div = 0;
        int sum = 0;

        for (int right = 0; right < k; right++) {
            sum += nums[right];
        }

        div = (double)sum / k;
        ans = div;

        for (int i = k; i < n; i++) {
            sum = sum - nums[left];
            left++;
            sum = sum + nums[i];
            ans = max(ans, (double)sum/k);
        }
        return ans;
    }
};