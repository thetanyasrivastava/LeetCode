class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0)
            return true;
        if(x<0)
            return false;
        int dup=x;
        long i=0;
        
        while(x>0)
        {
            i=i*10+x%10;
            x=x/10;
        }
        
        if(i==dup)
            return true;
        else
            return false;
    }
};
