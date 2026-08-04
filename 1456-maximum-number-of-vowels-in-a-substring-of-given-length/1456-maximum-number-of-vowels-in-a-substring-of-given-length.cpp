class Solution {
public:
    bool isVovel(char c){
        return c =='a'||c =='e'||c =='i'||c =='o'||c =='u';
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        int count = 0;

        for(int i = 0 ; i < k ; i++){
            if(isVovel(s[i])){
                count++;
            }
        }
        int left = 0;
        int ans = count;

        for(int right = k ; right < n ; right++){
            
            if(isVovel(s[left])){
                count--;
            }

            left++;

            if(isVovel(s[right])){
                count++;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};