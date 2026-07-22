class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int maxlen = 0;
        int currlen = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]>threshold){
                currlen = 0;
            }else if(currlen > 0 && nums[i] % 2 != nums[i-1] %2){
                currlen++;
            
            }else{
                currlen = (nums[i]%2==0)?1:0;
            }
            maxlen = max(maxlen,currlen);
        }
        return maxlen;
    }
};