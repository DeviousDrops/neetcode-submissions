class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total=nums.size();
        for(int i=0;i<nums.size();i++){
            total^=i;
            total^=nums[i];
        }
        return total;
    }
};