class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n  = nums.size();
        vector<int> ans(n);
        int l = 0;
        int r = n-1;
        int x;
        for(int i = n-1 ; i >=0 ; i--){
            if(abs(nums[l]) < abs(nums[r])){
                x = abs(nums[r]);
                r--;
            }else{
                x= abs(nums[l]);
                l++;
            }
            ans[i] = x*x;
        }
        return ans;
    }
};