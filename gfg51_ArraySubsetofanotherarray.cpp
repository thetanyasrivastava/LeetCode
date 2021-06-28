//https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

string isSubset(int a1[], int a2[], int n, int m) {
   /* 
   //Method- 4
   //T.C. = O(n) S.C. = O(n)
   string str="No";
    unordered_set<int> s;
    for(int i=0;i<n;i++)
        s.insert(a1[i]);
        
    for(int i=0;i<m;i++)
    {
        if(s.find(a2[i]) == s.end())
        {
            return str;
        }
    }
    str="Yes";
    return str;*/
    
    //MEthod - 3
     //T.C. = O(nlogn) + O(mlogm)
     string no="No";
     string yes="Yes";
     sort(a1,a1+n);
     sort(a2,a2+m);
     
     int i=0,j=0;
      if (n< m)
        return no;
     while(i<n && j<m)
     {
         if(a1[i]<a2[j])
            i++;
            
         else if(a1[i]==a2[j] && j==m-1)
        {
            return yes;
        }
        
        else if(a1[i]==a2[j])
        {
            i++;
            j++;
        }
       
        else if(a2[j]<a1[i])
            return no;
     }
     
     return (i<n)?no:yes;
}
