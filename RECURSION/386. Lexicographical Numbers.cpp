//ANOTHER APPROACH IS WITH CUSTOM SORT ,IN SORTING REPO
//CODE 1: NOT WELL OPTIMISED BUT JUST TO UNDERSTAND HOW RECURRSION WORKS
class Solution {
public:
    vector<int>ans;
    void solve(int &n,string&temp){
        int num=stoi(temp);
        if(num<1 || num>n)return ;
        ans.push_back(num);
        for(int i=0;i<=9;i++) {
        string prev=temp;
         temp+=to_string(i);
         solve(n,temp);
         temp=prev;
        }
    }
    vector<int> lexicalOrder(int n) {
        
        for(int i=1;i<=9;i++){
            string temp="";
            temp+=to_string(i);
            solve(n,temp);
        }
       
        return ans;
    }
};



//CODE 2: WELL STRUCTURED ,OPTIMISED CODE

class Solution {
public:
    vector<int>ans;
    void solve(int &n,int num){
        if(num>n)return ;
        ans.push_back(num);
        for(int i=0;i<=9;i++){
            int newNum=num*10+i;
            if(newNum>n)return;
            solve(n,newNum);
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=9;i++){
            solve(n,i);
        }
        return ans;
    }
};
