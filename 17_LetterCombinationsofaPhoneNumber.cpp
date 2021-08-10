class Solution {
public:
    /*Method - 1 Recursion T.C. = O(n*(4^n))
    
    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return {};
        
        string op="";
        vector<string> res;
        solve(digits,0,op,res);
        return res;
    }
    
    void solve(string digits,int index,string op,vector<string> &res)
    {
        vector<string> v={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if(digits.size()==index) //if(digits.size()==0)
        {
            res.push_back(op);
            return;
        }
        
        string s = v[digits[index] - '0'];
        //string s = v[digits[0] - '0'];   
        //digits.erase(digits.begin()+0);
        
        for(int i=0;i<s.length();i++)
        {
            //string op1 = op;
            //op1.push_back(s[i]);
            solve(digits,index+1,op+s[i],res);
        }
    }*/
    
    //Method - 2 Iterative
    /*vector<string> letterCombinations(string digits) {
    
        vector<string> v={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        
        vector<string> res;
        if(digits.size()==0)
       {
           return res;
       }
       res.push_back("");
        
        
        for(int k=0;k<digits.length();k++)
        {
            vector<string> temp;
            string s = v[digits[k] - '0'];   


            for(int i=0;i<s.length();i++)
            {
                for(int j=0;j<res.size();j++)
                {
                     temp.push_back(res[j]+s[i]);
                }
            }
               swap(temp,res);
           
       }
         
    return res;
    }*/
    
    //Method - 3 Queue
    vector<string> letterCombinations(string digits) {
    
        vector<string> phone={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
    if(digits.empty())
        return {};
    
        queue<string> q;
        vector<string> ans;
        
        q.push("");
        
        while(!q.empty())
        {
            string curr = q.front();
            q.pop();
            
            if(curr.length()==digits.length())
                ans.push_back(curr);
            else{
                string s = phone[digits[curr.length()] - '0'];
                for(auto x: s)
                    q.push(curr + x);
            }
            
        }
        return ans;
    }
};
