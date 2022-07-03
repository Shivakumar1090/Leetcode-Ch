class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int up = 1 , down = 1;
        if(n < 2)return 1;
        
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                up = down+1;
            }
            if(nums[i] < nums[i-1]){
                down = up+1;
            }
        }
        
        return max(down,up);
    }
};