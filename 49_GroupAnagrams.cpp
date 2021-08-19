class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        if(strs.size()==0)
            return anagrams;
        
        //using unorderd_map to store the sorted part as key and the anagrams as vector
        unordered_map<string,vector<string>> m;
        
        for(int i=0;i<strs.size();i++)
        {
            string s= strs[i];
            sort(s.begin(),s.end());
            m[s].push_back(strs[i]);
        }
        
        
        for(auto x: m)
        {
            anagrams.push_back(x.second);
        }
        
        return anagrams;
    }
    
    /*Time Complexity: O(n * (m * log(m)))

where n is the total number of strings present in the vector and m is the maximum length of a string in the vector. Here, sorting the strings causes (m * log(m)) addition to the complexity.
Space Complexity: O(n * m)*/
        
   /*     //Method -2 Counting Sort()
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        if(strs.size()==0)
            return anagrams;
        
        //using unorderd_map to store the sorted part as key and the anagrams as vector
        unordered_map<string,vector<string>> m;
        
        for(int i=0;i<strs.size();i++)
        {
            m[strSort(strs[i])].push_back(strs[i]);
        }
        
        
        for(auto x: m)
        {
            anagrams.push_back(x.second);
        }
        
        return anagrams;
    }
    
    string strSort(string s)
    {
        int counter[26]={0};
        
        for(char c:s)
            counter[c-'a']++;
        
        string t;
        for(int c=0;c<26;c++){
            
            t+=string(counter[c],c+'a');
        }
            
        
        return t;
    }*/
};
