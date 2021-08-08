class Solution{
public:

    vector<string> permutation(string S){
        // Code Here
        vector<string> res;
        string op="";
        op.push_back(S[0]);
        S.erase(S.begin()+0);
        solve(S,op,res);
        return res;
    }
    
    void solve(string S,string &op,vector<string> &res)
    {
        if(S.length()==0)
        {
            res.push_back(op);
            return;
        }
        
        string op1=op;
        string op2=op;
        
        op1+=" ";
        op1+=S[0];
        op2+=S[0];
        S.erase(S.begin()+0);
        
        solve(S,op1,res);
        solve(S,op2,res);
        
    }
};
