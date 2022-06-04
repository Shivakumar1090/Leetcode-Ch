class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            int indx = nums[i];
            nums[abs(indx)] = -1*nums[abs(indx)];
            if(nums[abs(indx)] > 0)return abs(indx);
        }
        
        return 0;
    }
};