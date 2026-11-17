class Solution {
public:
    int minSubArrayLen(int target, vector<int>& ar) {
        int l=0;
        int currsum = 0;
        int len = 0, minlen = INT_MAX;
        for(int i=0; i<ar.size(); i++){
            currsum+=ar[i];
            while(currsum>=target){
                minlen = min(minlen, i-l+1);
                currsum -= ar[l];
                l++;
            }
        }
        return (minlen==INT_MAX)?0:minlen;
    }
};