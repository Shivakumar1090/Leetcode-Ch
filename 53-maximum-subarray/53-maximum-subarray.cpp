class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = INT_MIN , mx = nums[0];
        
        for(int i = 0; i < n; i++)
        {
            if(sum <= 0)
                sum =0;
            sum += nums[i];
            mx = max(mx , sum);
        }
        return mx;
    }
};