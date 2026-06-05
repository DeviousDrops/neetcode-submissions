class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> m;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int s=-(nums[l]+nums[r]);
                if(s==nums[i]){
                    m.push_back({nums[i],nums[l],nums[r]});
                    while(nums[r]==nums[r-1]&&r>l){r--;}
                    r--;
                    while(nums[l]==nums[l+1]&&r>l){l++;}
                    l++;
                }
                else if(s<nums[i])
                    r--;
                else
                    l++;
            }
        }
        
        return m;
    }
};