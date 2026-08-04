class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        int r = *min_element(nums.begin(), nums.end());
        
        vector<int> count;
        unordered_set<int> s;
        for(int x : nums){
            s.insert(x);
        }

        for(int i = r ; i <=m ; i++){
           if(s.find(i) == s.end()){
            count.push_back(i);
           }
        }

        return count;
    }
};