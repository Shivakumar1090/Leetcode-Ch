class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prevsum;
        int n = nums.size() , currsum = 0;
        
        for(int i = 0; i < n; i++){
            currsum += nums[i];
            currsum %= k;
            
            if(currsum == 0 && i)return true;
            
            if(prevsum.find(currsum) != prevsum.end()){
                if(abs(prevsum[currsum] - i) > 1)
                        return true;
            }
            else prevsum[currsum] = i;
        }
        return false;
    }
};