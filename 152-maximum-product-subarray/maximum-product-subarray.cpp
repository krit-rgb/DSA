class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = nums[0];
        int minp = nums[0];
        int ans = nums[0];

        for(int i=1; i<nums.size(); i++){
            
            int newmax = max({nums[i], nums[i]*maxp, nums[i]*minp});
            int newmin = min({nums[i], nums[i]*maxp, nums[i]*minp});
            ans = max(ans, newmax);
            maxp=newmax;
            minp = newmin;
        }   
        return ans;
    }
};