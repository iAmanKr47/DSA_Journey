bool isRotated(string str1, string str2)
    {
        int n=str1.size();
        if(n!=str2.size()) return 0;
        
        string temp1="";
        string temp2="";
        //FOR CLOCKWISE ROTATION
        temp1+=str1[n-2];
        temp1+=str1[n-1];
        for(int i=0;i<n-2;i++){
           temp1+=str1[i];
        }
        if(temp1==str2)
        return 1;
        
        //FOR ANTI CLOCKWISE ROTATION
        for(int i=2;i<n;i++){
           temp2+=str1[i];
        }
        temp2+=str1[0];
        temp2+=str1[1];
        
         if(temp2==str2)
        return 1;
        
        
        return 0;
        
    }
