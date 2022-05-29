class Solution {
    int solve(string s , string t){
        int count[26] = {0};
        
        for(int i = 0; i < s.length(); i++){
            count[s[i]-'a'] = 1; 
        }
        
        for(int i = 0; i < t.length(); i++){
            if(count[t[i] - 'a'] == 1)return 0;
        }
        
        return s.length()*t.length();
    }
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        
        for(int i = 0; i < words.size(); i++){
            for(int j = i+1; j < words.size(); j++){
                int s = solve(words[i] , words[j]);
                ans = max(ans , s);
            }
        }
        
        return ans;
    }
};