class Solution {
public:
    int lcs(string word1,string word2,int l1,int l2 ,vector<vector<int>> &m){
        if(l1 == 0)return m[l1][l2]=l2;
        if(l2 == 0)return m[l1][l2]=l1;
        
        if(m[l1][l2] != -1)
            return m[l1][l2];
        
        if(word1[l1-1] == word2[l2-1]){
            return m[l1][l2] = lcs(word1,word2,l1-1,l2-1,m);
        }
        
        int insertC = lcs(word1,word2,l1,l2-1,m);
        int deleteC = lcs(word1,word2,l1-1,l2,m);
        int replace = lcs(word1,word2,l1-1,l2-1,m);
        
        return m[l1][l2] = 1+min({insertC , deleteC,replace});
    }
    int minDistance(string word1, string word2) {
        int l1 = word1.length() , l2 = word2.length();
        
        vector<vector<int>> memo(l1+1,vector<int>(l2+1,-1));
        
        int l = lcs(word1,word2,l1 ,l2 , memo);
        return l;
    }
};
