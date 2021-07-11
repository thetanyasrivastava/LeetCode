class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
       // Method -1 Sorting
       // T.C. = O(nlogn) S.C. =O(1)     // if same length
       // T.C. = O(1) // if length of the strings are unequal.
       // S.C. =O(1)  
        int n1=s.length();
        int n2=t.length();
        
        if(n1!=n2) return false;
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        for(int i=0;i<n1;i++)
        {
            if(s[i]!=t[i])
                return false;
        }
        return true;*/
        
        //Method - 2 Counting Character
       // T.C. = O(n) S.C. =O(1) 
        
        int n1=s.length();
        int n2=t.length();
        
        if(n1!=n2) return false;
        
        char count[256]={0};
        
        for(int i=0;i<n1;i++)
            count[s[i]]++;
        
        for(int i=0;i<n2;i++)
            count[t[i]]--;
        
        for(int i=0;i<256;i++)
        {
            if(count[i]!=0)
                return false;
        }
        return true;
        
       /* //Method - 3 map
       // T.C. = O(n) S.C. =O(n) 
        
        int n1=s.length();
        int n2=t.length();
        
        if(n1!=n2) return false;
        
        unordered_map<char,int> m;
        for(int i=0;i<n1;i++)
            m[s[i]]++;
        
        for(int i=0;i<n2;i++)
        {
            m[t[i]]--;
            if(m[t[i]]<0)
                return false;
        } 
        return true;
          */
    }
};
