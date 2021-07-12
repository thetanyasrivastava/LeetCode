class Solution {
public:
    
    //Method -1 Two Hashmaps
    
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())              // s=abacba, t=xyxzyx
            return false;                       // a-x, b-y, c-z
        
        unordered_map<char,char> mp1;
        unordered_map<char,bool> mp2;
        
        for(int i=0;i<s.length();i++)
        {
            //Case : 1
            if(mp1.find(s[i]) != mp1.end()) //If a is already present or not in mp1
            {                                  //a is present
                if(mp1[s[i]] != t[i])           // if it has the required map or not
                    return false;                  //if not then false.
            }
            else 
            {    
                // else means s[i] not present in mp1 -> Case :2
                if(mp2.find(t[i]) != mp2.end())     //if s[i] mapped t[i]isPresentINmp2 orNot
                    return false;               //mapped t[i] is present ,so false.
                else{  
                    //Case -3                
                    mp1[s[i]]=t[i];           //If s[i] not mapped to t[i]   
                    mp2[t[i]]=true;            // and if t[i] is also not marked true.
                }
            }
        }
        
        return true;
    }
    
    /*
    //Method - 2 One HashMap
    
    //To avoid "many to one" key value pair, we call the function again for t[i] by                 
    //interchanging "string s"  and "string t".
    
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        
        return helper(s,t) && helper(t,s);
    }
    
    bool helper(string s, string t)
    {
        unordered_map<char,char> mp;
        for(int i=0;i<s.length();i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                if(mp[s[i]] != t[i])
                    return false;
            }
            else
                mp[s[i]]=t[i];
        }
        return true;
    }*/
    
    
};
