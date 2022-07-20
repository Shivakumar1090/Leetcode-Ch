class Solution {
public:
    int subtractProductAndSum(int n) {
        long long int p = 1 , s = 0;
        
        while(n > 0){
            int rem = n % 10;
            p*=rem , s += rem;
            n /= 10;
        }
        
        return p-s;
    }
};