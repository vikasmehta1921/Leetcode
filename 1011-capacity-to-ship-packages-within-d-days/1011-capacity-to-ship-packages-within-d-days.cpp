class Solution {
public:
    int fun(vector<int>& weights, int cap){
        int day = 1 , load = 0;
        for(int i = 0 ; i < weights.size();i++){
            if(weights[i]+ load > cap){
                day++;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int left = *max_element(nums.begin(),nums.end());
        int right = accumulate(nums.begin(),nums.end(),0);

        while(left <= right){
            int mid = left + ( right - left)/2;

            if(fun(nums,mid) <= days){
                right = mid-1;
            }else{
                left = mid + 1;
            }
        }

        return left;
    }
};