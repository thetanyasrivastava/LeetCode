class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minm = findMin(strs);
        
        string res="";
        for(int i=0;i<minm;i++)
        {
            char curr=strs[0][i];
            
            for(int j=1;j<strs.size();j++)
            {
                if(strs[j][i]!=curr)
                    return res;
            }
             res.push_back(curr);
        }
        return res;
    }
    
    int findMin(vector<string>& strs)
    {
        int minm=strs[0].length();
        
        for(int i=1;i<strs.size();i++)
        {
            if(strs[i].length() < minm)
                minm=strs[i].length();
        }
        
        return minm;
    }
};
