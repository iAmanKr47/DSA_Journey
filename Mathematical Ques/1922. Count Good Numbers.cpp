//TOPIC: FAST MODULAR EXPONENTIATION
//prime numbers : 2,3,5,7
//even numbers:0,2,4,6,8
class Solution {
public:
    const int M = 1e9+7;
    int findPower(long long a,long long b){
        if(b==0) return 1;
        long long half = findPower(a,b/2);
        long long res = (half*half) % M;
        if(b%2==1) res = (res*a)%M;
        return res;
    }
    int countGoodNumbers(long long n) {
        return (1LL * findPower(5,(n+1)/2) * findPower(4,n/2)) % M;
    }
};
