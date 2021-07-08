class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        
        for(int i=n-1;i>=0;i--)   //traverse digits from the last digit(least significant)
        {  //since we begin from the last digit ,increamenting that digit by one may resultin 
            //overflow. Therefore,all elements PRIOR to digits[0] need to be considered since
            //there may be additional nines between digits[0],.....,digits[n];
            
            if(digits[i]==9)
                digits[i]=0;
            else{   //current digits is not 9 so we can safely increment by 1 and return
                digits[i]+=1;
                return digits;
            }
        }
        
        // If the program runs to this point, each 9 has become now 0,
        // to get the correct solution, we need to add one more element with a value of 0 
        //and set digits[0]=1 (in the most significant digit) to account for the carry digit.
        
        digits.push_back(0);
        digits[0]=1;
        return digits;
        
        
    }
};
