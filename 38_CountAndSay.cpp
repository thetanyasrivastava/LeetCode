class Solution {
public:
    string countAndSay(int n) {
        string finalString="1";
        if(n==1)
            return finalString;
        
        int countP=0, currentP=0;
        string s="";
        
        while(n>1)
        {
            while(countP < finalString.length())
            {
                while(finalString[currentP] == finalString[countP])
                    countP++;
                
                s += to_string(countP-currentP);
                s += finalString[currentP];
                currentP=countP;
            }
            
            finalString = s;
            s = "";
            countP=0;
            currentP=0;
            n--;
        }
        
        return finalString;
    }
};
