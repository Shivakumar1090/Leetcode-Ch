class Solution {
public:
    bool isHappy(int n) {
        if(n == 1)return true;
        if(n == 7)return true;
        if(n < 10)return false;
        // if(n < 10)return false;
        
        int c = 0;
        while(n > 0){
            int r = n%10;
            n /= 10;
            int m = r*r;
            c += m;
        }
        
        return isHappy(c);
    }
};