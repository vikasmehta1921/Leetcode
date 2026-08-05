class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;

        while(l<r){
            int mid = l + (r-l)/2;

            if(nums[mid]>nums[r]){// rotion in right side min element right side
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return nums[l];
    }
};