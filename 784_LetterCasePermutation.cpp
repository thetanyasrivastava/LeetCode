class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        string op="";
        solve(s,op,res);
        return res;
    }
    
    void solve(string s,string op,vector<string> &res)
    {
        if(s.length()==0)
        {
            res.push_back(op);
            return;
        }
        
        if(isalpha(s[0]))
        {
            string op1=op;
            string op2=op;
            
            op1.push_back(tolower(s[0]));
            op2.push_back(toupper(s[0]));
            
            s.erase(s.begin()+0);
            
            solve(s,op1,res);
            solve(s,op2,res);
        }
        else{
            string op1=op;
            op1.push_back(s[0]);
            s.erase(s.begin()+0);
            solve(s,op1,res);
        }
        
    }
};
