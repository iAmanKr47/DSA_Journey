//same as ques no. 476
//watch MIK VIDEO

//CODE 1:BRUTE FORCE
int findComplement(int num) {
        string str="";
        while(num>0){
            int rem=num%2;
            str+=rem==0?'0':'1';
            num/=2;
        }
        //str will now contain binary represenation in reverse order;
        int ans=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='0')ans+=pow(2,i);
        }
        return ans;
    }

//CODE 2: BUT MANIPULATION USING XOR
int bitwiseComplement(int n) {
        if(n==0)return 1;
        int numOfBitsToRepresentN=(int)(log2(n))+1;
        for(int i=0;i<numOfBitsToRepresentN;i++){
            n= n^(1<<i);
        }
        return n;
    }

//CODE 3: BUT MANIPULATION USING XOR AND MASK
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int numOfBitsToRepresentN=(int)((log2(n))+1);
        int mask=(1<<numOfBitsToRepresentN) -1;
        return n ^ mask;
    }
};
