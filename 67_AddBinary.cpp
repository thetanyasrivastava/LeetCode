class Solution {
public:
    string addBinary(string a, string b) {
        
        string res;
        
        int i=a.length()-1 ,j=b.length()-1;
        int carry=0,sum;
        
        
        while(i>=0 || j>=0)
        {
            int p = i>-1 ? a[i] - '0' : 0;
            int q = j>-1 ? b[j] - '0' : 0;
            sum = p + q + carry;
            res += to_string(sum%2);
            carry = sum/2;
            
            i--,j--;
        }
        
        if(carry == 1)
            res += to_string(1);
        
        reverse(res.begin(),res.end());
        return res;
    }
};
