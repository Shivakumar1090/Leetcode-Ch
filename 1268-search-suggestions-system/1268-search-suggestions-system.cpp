class Solution {
public:
    string substr(int st, int e , string s){
        string sub;
        for(int i = st; i <= e; i++){
            sub += s[i];
        }
        return sub;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin() , products.end());
        string curr;
        
        for(int i = 0; i < searchWord.length(); i++){
            curr += searchWord[i];
            vector<string> v;
            for(int j = 0; j < products.size(); j++){
                // if(searchWord.length() > products[j].length())continue;
                int val = 0; 
                if(products[j].length() > i)val = i; 
                else val = products[j].length();
                string sub = substr(0,val, products[j]);
                if(v.size() == 3)break;
                if(curr == sub){
                    v.push_back(products[j]);
                }
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};