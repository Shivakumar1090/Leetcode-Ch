class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        
        for(int i = 0; i < words.size(); i++){
            mp[words[i]]++;
        }
        
        int count = 0;
        
        for(auto it: mp){
            string curr = it.first;
            int p1 = 0 , p2 = 0;
            
            while(p1 < curr.size() && p2 < s.size()){
                if(curr[p1] == s[p2]){
                    p1++,p2++;
                }
                else{
                    p2++;
                }
            }
            
            if(p1 == curr.size())count+=it.second;
        }
        
        return count;
    }
};