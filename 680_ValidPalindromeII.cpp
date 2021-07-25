class Solution {
public:
    bool validPalindrome(string s) {
        int l=0,r=s.length()-1;
        while(l<=r)
        {
            if(s[l]!=s[r])
            {
                return palin(s,l+1,r) || palin(s,l,r-1);
            }
            l++;
            r--;
        }
        return true;
    }
    
    bool palin(string s,int l, int r)
    {
        while(l<=r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
