class Solution {
public:
    string multiply(string num1, string num2) 
    {
        //handle edge-case where either or both of them is 0
        if(num1=="0" || num2=="0")
            return "0";
        int n1=num1.length(), n2=num2.length();
        
        //n1+n2 = maximum length
        vector<int> res(n1+n2,0);
        
        int i,j,carry, prod;
        for(i=n2-1;i>=0;i--)
        {   
            carry=0;
            for(j=n1-1;j>=0;j--)
            {
                prod=(num2[i]-'0') * (num1[j]-'0') +carry + res[i+j+1];
                res[i+j+1] = prod % 10;
                carry = prod / 10;
                cout<<res[i+j+1]<<" ";
            }
            if(carry>0)     //for cases like 9 * 99 
                res[i+j+1]=carry;
        }
       
        
        // to skip leading 0's
        int k=0;
        while(k<res.size() && res[k]==0)
            k++;
        
        //transform the vector to a string
        string s;
        while(k<res.size())
        {
            s.push_back(res[k++] + '0');
          //cout<<s[k]<<" ";
        }
        
        return s;
    }
};
