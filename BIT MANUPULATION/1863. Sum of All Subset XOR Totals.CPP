//TOPIC TAGS: BIT MANIPULATION ,RECURRSION ,BACKTRACKING
// 1) reverse of XOR is DOING XOR ONE MORE TIME
// 2) XOR OF A NUMBER WITH 0 IS THE NUMBER ITSELF
class Solution {
public:
int sum=0;
void solve(vector<int>& nums,int i,int &currXor){
    if(i>=nums.size()) return ;
    currXor^=nums[i];
    sum+=currXor;
    solve(nums,i+1,currXor);
    currXor^=nums[i];//reverse of xor is xor itself
    solve(nums,i+1,currXor);
}
    int subsetXORSum(vector<int>& nums) {
        int i=0;
        int currXor=0;
        solve(nums,i,currXor);
        return sum;
    }
};
