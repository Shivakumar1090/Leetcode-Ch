class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p = 1;
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            p *= nums[i];
            ans = max(p,ans);
            if(p == 0){
                p = 1;
            }
        }
        p = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            p *= nums[i];
            ans = max(p,ans);
            if(p == 0){
                p = 1;
            }
        }
        if(ans == INT_MIN)return -1;
        return ans;
    }
};