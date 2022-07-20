class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int start = 0,end=nums.size()-1;
        vector<int> res(nums.size());
        int pos = nums.size()-1;
        
        while(start <= end){
            int s = abs(nums[start]) , e = abs(nums[end]);
            if(s < e){
                res[pos] = e*e;
                pos--;
                end--;
            }
            else{
                res[pos] = s*s;
                pos--;
                start++;
            }
        }
        
        return res;
    }
};