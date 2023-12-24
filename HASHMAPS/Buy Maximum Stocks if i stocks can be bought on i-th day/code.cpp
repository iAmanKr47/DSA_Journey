int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        //mappping of price and maxUnits of that stocks that we can have 
        //map will store stock price in increasing order (helpful for line 28);
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[price[i]]+=i+1;
        }
        
        int cnt=0;
        for(auto ele:mp){
            
            auto availStocks=ele.second;
            auto price=ele.first;
            int minBuy=min(k/price,availStocks);
            cnt+=minBuy;
            k-=(minBuy*price);
            
            if(k<price){ //to decrease the steps cz its waste of time to check further if this condtion meets
                return cnt;
            }
            
        }
       return cnt; 
    }
