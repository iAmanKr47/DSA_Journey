bool isRotated(string str1, string str2)
    {
        if(str1.size()!=str2.size())return 0;
        int n=str1.size();
        bool clockd=true;
        bool anticlockd=true;
        //for anti clockwise 
        for(int i=2;i<n;i++)
        if(str1[i]!=str2[i-2]){
            anticlockd=false;
            break;
        }
        if(str1[0]!=str2[n-2]&&str1[1]!=str2[n-1])anticlockd=false;
        
        //for clockwise
       for(int i=0;i<n-2;i++)
        if(str1[i]!=str2[i+2]){
            clockd=false;
            break;
        } 
        if(str2[0]!=str1[n-2]&&str2[1]!=str1[n-1])clockd=false;
        if(clockd||anticlockd)
        return 1;
        
        return 0;
    }
