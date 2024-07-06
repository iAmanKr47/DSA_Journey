
int passThePillow(int n, int time) {
        if(time<=n-1)return time+1;
        int roundTime=n-1;//time required to complete one round
        int round=time/roundTime;//number of rounds completed
        int remainder=time%roundTime;//no of persons required to complete the current round
        if(round%2!=0) return n-remainder;//if completed round is odd therefore we are cuurently on reverse path 
        return remainder+1;//we are cuurently in forward path
    }
