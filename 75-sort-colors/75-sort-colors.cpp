class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        if(n > 1){
            int count_0 = count(nums.begin() , nums.end() , 0);
            int count_1 = count(nums.begin() , nums.end() , 1);
            int count_2 = n-(count_0+count_1);

            if(count_0 != 0){
                for(int i = 0; i < count_0; i++){
                    nums[i] = 0;
                }
            }
            if(count_1 != 0){
                for(int i = count_0; i < count_1+count_0; i++){
                    nums[i] = 1;
                }
            }
            if(count_2 != 0){
                for(int i = count_1+count_0; i < n; i++){
                    nums[i] = 2;
                }
            }
        }
    }
};