//CUSTOM SORT

class Solution {
public:
static bool myComperator(string &a,string&b){
    int n1=a.size();
    int n2=b.size();
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(a[i]==b[j]){
            i++;
            j++;
        }
        else return a[i]<b[j];
    }
    return n1<n2;

}
    vector<int> lexicalOrder(int n) {
    
       vector<string>v;
        vector<int>ans;
       for(int i=1;i<=n;i++)v.push_back(to_string(i));
       sort(begin(v),end(v),myComperator);
       for(auto i:v)ans.push_back(stoi(i));
       return ans;

    }
};
