class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalsum = nums[0];
        for(int i=1; i<nums.size(); i++){
            totalsum+=nums[i];
        }

        int mins = nums[0];
        int curr = nums[0];
        for(int i=1; i<nums.size(); i++){
            curr = min(nums[i], nums[i]+curr);
            mins = min(mins, curr);
        } 

        int maxs = nums[0];
        curr = nums[0];
        for(int i=1; i<nums.size(); i++){
            curr = max(nums[i], nums[i]+curr);
            maxs = max(maxs, curr);
        } 
        if(maxs<0) return maxs;

        return max(maxs, totalsum - mins);
    }
};