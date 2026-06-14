class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int mid=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(target==nums[mid])
                return mid;
            else if(nums[mid]>nums[r]&&(nums[mid]<target||nums[r]>=target)||nums[mid]<=nums[r]&&target<=nums[r]&&nums[mid]<target)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;        
    }
};