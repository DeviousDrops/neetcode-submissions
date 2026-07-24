class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m=nums[0];
        int sum=0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>=0){
                sum+=nums[i];
                m=max(sum,m);
            }
            else
                sum=0;
            m=max(m,nums[i]);
        }   
        return m; 
    }
};