class Solution{
	public:
		 int mod = 1e9 + 7;
		 //fibonacci series and frodg jump question of recurrsion
		int nthPoint(int n){
		    if(n == 0 || n == 1)
		        return 1;
		        int prevStep=1;
		        int prevPrevStep=1;
		        int currStep;
		    for(int i=2; i<=n; i++){
		        currStep=(prevStep+prevPrevStep)%mod;
		        prevStep=prevPrevStep;
		        prevPrevStep=currStep;
		    }   
		    return currStep;
		}
};
