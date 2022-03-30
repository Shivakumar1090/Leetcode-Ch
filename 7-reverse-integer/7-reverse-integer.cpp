class Solution {
public:
    int reverse(int x) {
        long long int ans = 0;
        string s = to_string(x);
  
        bool minus = false;
        int n = s.length();
        
        if(s[0] == '-'){
            for(int i = n-1; i > 0; i--){
                if(ans>INT_MAX/10 || ans<INT_MIN/10){
                    return 0;
                }
                ans = ans*10+s[i]-'0';
            }
            return -1*ans;
        }
        
        for(int i = n-1; i >= 0; i--){
            if(ans>INT_MAX/10 || ans<INT_MIN/10){
                return 0;
            }
            ans = ans*10+s[i]-'0';
        }
        return ans;
    }
};