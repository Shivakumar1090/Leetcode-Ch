class Solution {
public:
    int maxScore(vector<int>& nums ,int k) {
        int n = nums.size(),res = 0;
        for(int i = 0; i < k; i++)res += nums[i];
        
        int curr = res;
        for(int i = k-1; i >= 0; i--){
            curr -= nums[i];
            curr += nums[n-k+i];
            
            res = max(res,curr);
        }
        
        return res;
    }
};