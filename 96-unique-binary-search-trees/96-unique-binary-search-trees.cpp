class Solution {
public:
    long long int binomialCoeff(int n, int r){
        if(r > n-r){
            r = n-r;
        }
        long long int res = 1;
        
        for(int i = 0; i < r; i++){
            res *= (n-i);
            res /= (i+1);
        }
        
        return res;
    }
    int numTrees(int n) {
        
        long long int val = binomialCoeff(2*n, n);
        return val/(n+1);
    }
};