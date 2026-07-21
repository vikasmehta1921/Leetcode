class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int countones = count(begin(s),end(s),'1');
        vector<int> zeroes;
        int i = 0;
        while(i<n){
            if(s[i]=='0'){
                int start = i;
                while(i<n && s[i] == '0'){
                    i++;
                }
                zeroes.push_back(i-start);
            }else{
                i++;
            }
        }
        int maxses = 0;
        for(int i = 1 ; i < zeroes.size() ; i++){
            maxses = max(maxses ,zeroes[i] + zeroes[i-1]);
        }

        return maxses+countones;
    }
};