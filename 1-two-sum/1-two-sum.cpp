class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        vector<int> v(2);
        
        for(int i = 0; i < n; i++){
            int x = target-nums[i];
            if(mp.find(x) != mp.end()){
                v[0] = mp[x];
                v[1] = i;
            } 
            else{
                mp[nums[i]] = i;
            }
        }
        
        return v;
    }
};