//HEAP + GREEDY APPROACH

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>>pq;
        int freq[26]={0};
        for(auto i:s)freq[i-'a']++;
        for(int i=0;i<26;i++) if(freq[i]!=0)pq.push({'a'+i,freq[i]});
        string ans="";
        if(pq.size()==1){
            ans.append(min(pq.top().second,repeatLimit),s[0]);
            return ans;
        }
        while(pq.size()>1){
            auto top=pq.top();
            pq.pop();
            int occ1=top.second;
            char ch1=top.first;
            int cnt1=min(repeatLimit,occ1);

            if(ans.size()>0 && ans.back()==ch1){
              auto top2=pq.top();
              pq.pop();
              int occ2=top2.second;
              char ch2=top2.first;
              int cnt2=min(1,occ2);
              ans.append(cnt2,ch2);
              if(occ2-cnt2>0)pq.push({ch2,(occ2-cnt2)});
            }
            
            ans.append(cnt1,ch1);
            if(occ1-cnt1>0)pq.push({ch1,(occ1-cnt1)});
            
        }
        if(pq.size()>0 && pq.top().first!=ans[ans.size()-1]){
           char ch=pq.top().first;
           int occ=pq.top().second;
           int cnt=min(repeatLimit,occ);
           ans.append(cnt,ch);
        }
        return ans;
    }
};
