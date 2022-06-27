class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0)return 0;
        if(left == right)return left;
        int start = 0;
        while(true){
            long long int curr = pow(2,start);
            if(curr > left){
            if(curr > right)break;
            if(curr >= left && curr <= right)return 0;
            }
            start++;
        }
        int ans = right;
        for(int i = right-1; i>=left; i--){
            ans = ans & i;
        }
        
        return ans;
    }
};