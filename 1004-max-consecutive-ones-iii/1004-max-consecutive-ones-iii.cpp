class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int n = nums.size();
        int zerocount = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            if (nums[right] == 0) {
                zerocount++;
            }

            while(zerocount > k) {
                if (nums[left] == 0) {
                    zerocount--;
                }
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};