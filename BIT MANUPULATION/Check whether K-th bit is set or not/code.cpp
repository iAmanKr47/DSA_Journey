bool checkKthBit(int n, int k)
    {
        //right shift the given  number n by k position
        //IF AND of that bit with 1 is also 1 ,this means that bit was a set bit else not 
       if(n>>k&1==1) return true;
        return false;
    }
