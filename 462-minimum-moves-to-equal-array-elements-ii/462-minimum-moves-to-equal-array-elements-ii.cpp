class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size() , sum = 0;
        sort(nums.begin() , nums.end());
        
        int ans = 0;
        
        for(int i = 0; i < n/2; i++){
            ans += nums[n-i-1]-nums[i];
        }
        
        return ans;
    }
};