class Solution {
public:
    int fib(int n) {
        if(n == 0)return 0;
        int prev = 1 , prev1 = 1 , curr_i = 0;
        
        for(int i = 3; i <= n; i++)
        {
            curr_i = prev+prev1;
            prev1 = prev;
            prev = curr_i;
        }
        return prev;
    }
};