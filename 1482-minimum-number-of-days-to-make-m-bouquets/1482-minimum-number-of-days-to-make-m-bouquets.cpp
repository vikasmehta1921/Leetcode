class Solution {
public:
    bool fun(vector<int>& nums, int day, int m, int k) {
        int nob = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= day) {
                count++;
            } else {
                nob += count / k;
                count = 0;
            }
        }
        nob += count / k;
        return nob >= m;
    }
    int minDays(vector<int>& nums, int m, int k) {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        if((long long)m * (long long)k > nums.size()) return -1;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (fun(nums, mid, m, k)) {
                    r = mid-1;
                } else {
                    l = mid + 1;
                }
            }
        return l;
    }
};