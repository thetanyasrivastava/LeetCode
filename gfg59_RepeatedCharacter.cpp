char firstRep (string s)
    {
        //code here
        
        int count[26]={0};
        for(int i=0;i<s.length();i++)
        {
            count[s[i]-'a']++;
        }
            
        for(int i=0;i<s.length();i++)
        {
            if(count[s[i]-'a']>1)
            {
                return s[i];
            }
        }
        return '#';
        
        
        
        /*
        //Wrong method but important to note
        char count[256]={0};
        for(int i=0;i<s.length();i++)
        {
            count[s[i]]++;
        }
            
        for(int i=0;i<256;i++)
        {
            if(count[i]>1)
            {
                //cout<<i;
                return (char)i;
            }
        }
        return '#';*/
    }
