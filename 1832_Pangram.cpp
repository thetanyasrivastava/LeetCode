class Solution {
public:
    
    //Method-2 Efficient Solution 
    //T.C. = O(n)       // S.C. = O(1)
    bool checkIfPangram(string sentence) {
       int n=sentence.length();
        if(n<26)
            return false;
        vector<bool> visited(26);
        for(int i=0;i<n;i++)
        {
            char x=sentence[i];
            if(x>='a' && x<='z')
                visited[x-'a']=true;
        }
        
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==false)
                return false;
        }
        return true;
    
    
    /*//Method-3 Map
    //T.C. = O(n)       // S.C. = O(n)
    bool checkIfPangram(string sentence) {
    int n=sentence.length();
        if(n<26)
            return false;
        unordered_map<char,int> m;
        
        for(int i=0;i<n;i++)
        {
            m[sentence[i]]++;
        }
        
        return m.size()==26 ?  true :false;*/
    }
};
