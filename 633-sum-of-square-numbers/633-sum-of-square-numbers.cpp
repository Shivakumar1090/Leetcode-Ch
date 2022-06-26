class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0 , s = sqrt(c) , r = s; 
        // if(c == 1)return true;
        while(l <= r){
            int l2 = l*l;
            int r2 = r*r;
            if(l2 == c-r2)return true;
            if(l2 > c-r2)r--;
            else l++;
        }
        
        return false;
    }
};