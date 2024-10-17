int maximumSwap(int num) {
        if(num<10)return num;

        string str=to_string(num);
        int n=str.size();
        for(int i=0;i<n;i++){
            int maxi=str[i]-'0'; //test case : num=98368
            int index;
            for(int j=n-1;j>i;j--){ //test case :num=1993
                if(str[j]-'0'>maxi){
                    maxi=str[j]-'0';
                    index=j;
                }
            }
            if(maxi!=str[i]-'0'){
                swap(str[i],str[index]);
                break;
            }
        }
        
        return stoi(str);
    }
