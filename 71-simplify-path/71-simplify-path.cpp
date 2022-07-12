class Solution {
public:
    string simplifyPath(string path) {
        stack<string> myStack;
        string ans;
        
        for(int i = 0; i < path.length(); i++){
            if(path[i] == '/')continue;
            string curr;
            
            while(i < path.length() && path[i] != '/')
                curr += path[i] , i++;
            
            if(curr == "."){
                continue;
            }
            else if(curr == ".."){
                if(!myStack.empty())
                    myStack.pop();
            }
            else{
                myStack.push(curr);
            }
        }
        
        // ans += '/';
        while(!myStack.empty()){
            string curr = myStack.top();
            myStack.pop();
            // ans = '/';
            ans = '/' + curr + ans;
            // if(!myStack.empty())ans += "/";
        }
        
        if(ans.size() == 0)return "/";
        
        return ans;
    }
};