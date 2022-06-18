class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size() , lastIndx = 0 , firstIndx = 0;
        vector<int> c = nums;
        sort(c.begin() , c.end());
        
        for(int i = 0; i < n; i++){
            if(nums[i] != c[i]){
                firstIndx = i+1;
                break;
            }
        }
        
        for(int i = n-1; i >= 0; i--){
            if(nums[i] != c[i]){
                lastIndx = i+1;
                break;
            }
        }
        
        if(lastIndx - firstIndx == 0)return 0;
        
        return lastIndx-firstIndx+1;
    }
};