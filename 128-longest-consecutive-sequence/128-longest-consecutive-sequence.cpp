class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        s.insert(nums.begin() , nums.end());
        int ans = 0;
        
        for(auto it: s){
            if(s.count(it-1))continue;
            int j = 1;
            while(s.count(it+j))j++;
            ans = max(ans,j);
        }
        
        return ans;
    }
};