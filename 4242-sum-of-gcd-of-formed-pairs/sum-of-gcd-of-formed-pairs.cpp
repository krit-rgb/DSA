class Solution {
public:
    int gcd(int a, int b){
        while(b!=0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        vector<int> pg(nums.size());
int mx = nums[0];
        for(int i=0; i<nums.size(); i++){
            mx = max(mx, nums[i]);
    pg[i] = gcd(nums[i], mx);
        }

        sort(pg.begin(), pg.end());

        int i=0; int j=nums.size()-1;
        long long sum =0;
        while(i<j){
            sum+=gcd(pg[i], pg[j]);
            i++; j--;
        }       

        return sum; 
    }
};