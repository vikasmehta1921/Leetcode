class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int n = nums.size();
        int firstmax = INT_MIN;
        int secmax = INT_MIN;
        int thmax = INT_MIN;

        int firstmin = INT_MAX;
        int secmin = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums[i] > firstmax) {
                thmax = secmax;
                secmax = firstmax;
                firstmax = nums[i];
            } else if (nums[i] > secmax) {
                thmax = secmax;
                secmax = nums[i];

            } else if(nums[i]>thmax) {
                thmax = nums[i];
            }

            if (nums[i] < firstmin) {
                secmin = firstmin;
                firstmin = nums[i];
            } else if (nums[i] < secmin) {
                secmin = nums[i];
            }
        }

        int a = firstmax * secmax * thmax;
        int b = firstmax * firstmin * secmin;

        return max(a, b);
    }
};