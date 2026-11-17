class Solution {
public:
    int maxSubArray(vector<int>& ar) {
        int sum = 0;
        int maxsum=INT_MIN;
        for(int i=0; i<ar.size(); i++){
            sum+=ar[i];
            maxsum=max(sum, maxsum);
            if(sum<0){
                sum=0;
            }
            
        }
        return maxsum;
    }
};