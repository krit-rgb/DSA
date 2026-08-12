class Solution {
public:
    int minSubArrayLen(int t, vector<int>& ar) {

        int sum = 0;
        int ans = INT_MAX;
        int low = 0;
        
        for(int i=0; i<ar.size(); i++){
            if(ans==1){
                return 1;
            }

            sum+=ar[i];
            while(sum>=t){
                ans=min(ans, i-low+1);
                sum-=ar[low];
                low++;
            }
        }   

            
            return ans==INT_MAX?0:ans;

    }
};