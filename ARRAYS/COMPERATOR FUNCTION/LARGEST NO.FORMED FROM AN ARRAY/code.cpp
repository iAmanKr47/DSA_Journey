CODE 1:
class Solution{
public:
	static bool compareString(string a ,string b) {
	    return a+b > b+a;
	}
	string printLargest(int n, vector<string> &arr) {
	    if(n==1)return arr[0];
	    string ans="";
	    sort(arr.begin(),arr.end(),compareString);
	    
	    for(auto i:arr) ans+=i;
	    return ans;
	    
	}
};

CODE 2:
  
bool compareString(string a ,string b) {
	    return a+b > b+a;
	}
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings

	string printLargest(int n, vector<string> &arr) {
	    if(n==1)return arr[0];
	    string ans="";
	    sort(arr.begin(),arr.end(),compareString);
	    
	    for(auto i:arr) ans+=i;
	    return ans;
	    
	}
};
