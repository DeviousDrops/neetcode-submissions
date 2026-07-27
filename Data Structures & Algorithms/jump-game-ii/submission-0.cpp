class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int m=nums[0];
        if(n==1)
            return 0;
        int c=1;
        int p=nums[0];
        for(int i=0;i<n-1;i++){
            
            if(nums[i]+i>m){
                m=nums[i]+i;    
            }
            if(i==p){
                p=m;
                c++;
                }
        }        
        return c;
    }
};