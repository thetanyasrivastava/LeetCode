class Solution {
public:
    /*int longestPalindrome(string s) {
        
        //Method - 1 : Map
        unordered_map<char,int> mp;
        
        int len=0;
        //for(int i=0;i<s.length();i++)
        for(char ch: s)
        {
            //char ch=s[i];
            if(mp.find(ch) != mp.end())
            {
                len+=2;
                mp.erase(ch);
            }
            else
                mp[ch]++;
        }
        
        return mp.size()>0 ? len+1 : len;
    }
    */
    //MEthod -2 : Set
    int longestPalindrome(string s) {
        unordered_set<char> st;
        
        int len=0;
        //for(int i=0;i<s.length();i++)
        for(char ch: s)
        {
            //char ch=s[i];
            if(st.find(ch) != st.end())
            {
                len+=2;
                st.erase(ch);
            }
            else
                st.insert(ch);
        }
        
        return st.size()>0 ? len+1 : len;
    }
};
