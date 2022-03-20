class Solution {
public:
    int countOdds(int low, int high) {
        int n;
 if(low%2==0&&high%2==0)
     n=(high-low)/2;
        else if(low%2!=0&&high%2!=0)
            n=(high-low)/2+1;
        else 
        {
            if(low%2==0)
                n=(high-low+1)/2;
            else
                n=(high-low+1)/2;
        }
            
        
        return(n);
    
    }
};