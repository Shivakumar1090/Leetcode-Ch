class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        int r = n-k;
        
        reverse(nums.begin() ,nums.end());
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end()-r);
    }
};