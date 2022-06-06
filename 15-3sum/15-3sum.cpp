class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        
        if(n < 3)return ans;
        
        for(int i = 0; i < n; i++){
            if(nums[i] > 0)break;
            
            if(i > 0 && nums[i] == nums[i-1])continue;
            
            int start = i+1 , end = n-1 , sum = 0;
            
            while(start < end){
                sum = nums[i]+nums[start]+nums[end];
                if(sum < 0){
                    start++;
                } 
                else if(sum > 0){
                    end--;
                }
                else{
                    ans.push_back({nums[i] , nums[start] , nums[end]});
                    int l = nums[start] , r = nums[end];
                    
                    while(start < end && nums[start] == l)start++;
                    while(start < end && nums[end] == r)end--;
                }
            }
            
        }
        
        
        return ans;
    }
};