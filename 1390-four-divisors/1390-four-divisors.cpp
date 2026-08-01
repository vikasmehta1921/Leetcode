class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            int sum2 = 0;
            for (int j = 1; j <= nums[i]; j++) {
                if (nums[i] % j == 0) {
                    count++;
                    sum2 += j;
                }
                if (count > 4) {
                    break;
                }
            }
            if (count == 4) {
                sum += sum2;
            }
        }
        return sum;
    }
};