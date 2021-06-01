class Solution {
  public:
    string revStr(string S) {
        // code here
        int n=S.length();
        
        int start=0, end=n-1;
        
        while(start<end)
        {
            swap(S[start],S[end]);
            start++;
            end--;
        }
        return S;
    }
};
