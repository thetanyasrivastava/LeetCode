class Solution {
public:
   /*//Technique-1 
   string addStrings(string num1, string num2) {
        
        //to check if num2 has greater digits than num1
        if(num1.size()<num2.size())
            return addStrings(num2,num1);
        
        //to traverse from last till first
        int i=num1.size()-1;        //num1= 92859   num2=293
        int j=num2.size()-1;
        
        string result;
        int carry=0;
        int sum;
        
        //will check upto j's first character as num2<num1
        while(j>=0)         //num2=293
        {
            sum = num1[i]-'0' + num2[j]-'0' + carry;
            result += to_string(sum%10);    //to calculate the last digit of 2digited sum
            carry = sum/10;              //to calculate the carry(first digit) in 2digitedsum
            i--,j--;
        }
        //stopped when j<0 and i=1
        
        //as num2 was smaller so it got over first, same process for num1 as there were few             //more characters to add
        while(i>=0)     //num1=92859
        {
            sum=num1[i]-'0'+carry;
            result += to_string(sum%10);
            carry=sum/10;
            i--;
        }
        
        //edge case : 99+1=100
        if(carry==1)
            result += to_string(carry);
        
        reverse(result.begin(),result.end());
        return result;
    }*/
    
    
    //Technique-2
    string addStrings(string num1, string num2) {
        
        int i=num1.size()-1;
        int j=num2.size()-1;
        
        string res;
        int carry=0, sum;
        
        while(i>=0 ||j>=0)
        {
            int d1 = i>-1 ? num1[i]-'0' : 0;
            int d2 = j>-1 ? num2[j]-'0' : 0;
            sum=d1+d2+carry;
            res += to_string(sum%10);
            carry = sum/10;
            
            i--,j--;
        }
        
        if(carry==1)
            res += to_string(1);
        
        reverse(res.begin(),res.end());
        return res;
    }
};
