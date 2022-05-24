class Solution {
public:
    int largestCombination(vector<int>& c) {
        vector<int> bits(32);
        
        for(int i = 0; i < c.size(); i++){
            int j = 31;
            while(c[i] > 0){
                bits[j] += c[i]%2;
                c[i] = c[i]/2;
                j--;
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < 32; i++){
            ans = max(ans , bits[i]);
        }
        
        return ans;
    }
};