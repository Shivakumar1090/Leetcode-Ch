class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> s;
        
        
        sort(nums.begin() , nums.end());
        
        for(int i = 0; i < n; i++){
            
            for(int j = i+1; j < n; j++){
                int newTarget = target-nums[i]-nums[j];
                
                int start = j+1 , end = n-1;
                while(start < end){
                    int sum = nums[start]+nums[end];
                    if(sum < newTarget)start++;
                    else if(sum > newTarget)end--;
                    else{
                        s.insert({ nums[i] , nums[j] , nums[start] , nums[end] });
                        start++ , end--;
                    }
                }
            }
        }
        
        for(auto it: s)ans.push_back(it);
        
        return ans;
    }
};