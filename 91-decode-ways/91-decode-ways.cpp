class Solution {
public:
    int rec(string &s,int i,int n,vector<int> &m){
        if(i < n && s[i] == '0')return 0;
        if(i >= n)return 1;
        
        if(m[i] != -1)return m[i];
        
        int ways = 0;
        
        if(s[i] != '0')ways = rec(s,i+1,n,m);
        
        if(i+1 < n && ((s[i] == '1' && s[i+1] <= '9') || (s[i]=='2' && s[i+1] < '7')))
            ways += rec(s,i+2,n,m);
        
        return m[i] = ways;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> m(n+1 , -1);
        return rec(s,0,n,m);
    }
};