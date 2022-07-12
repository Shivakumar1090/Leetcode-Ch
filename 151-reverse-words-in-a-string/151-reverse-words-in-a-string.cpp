class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ')continue;
            
            string curr;
            
            while(s[i] != ' ' && i < s.length()){
                curr += s[i];
                i++;
            }
            
            st.push(curr);
        }
        
        string ans;
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(!st.empty())ans += ' ';
        }
        
        return ans;
    }
};