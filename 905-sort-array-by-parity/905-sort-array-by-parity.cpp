class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size() , start = 0 , end = n-1 , temp = 0;
        
        while(start<end){
            if(nums[start] % 2 == 0){
                start++;
            }
            else{
                swap(nums[start] , nums[end]);
                end--;
            }
        }
        
        return nums;
    }
};