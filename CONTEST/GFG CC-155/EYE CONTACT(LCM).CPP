

CODE2: USING GCD
 
Implementation
First calculate the GCD of n and m with the builtin functions.
Then As we know there is a relation between LCM and GCD, I,e: n*m = LCM*GCD of these numbers
So we can easily find the value of LCM using these equation.

class Solution {
  public:
    long long firstContact(int n, int m) {
        long long ans = m / __gcd(n, m);
        ans *= n;
        return ans;
    }
};
