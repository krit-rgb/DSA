class Solution {
public:
    vector<int> productExceptSelf(vector<int>& ar) {
        vector<int> ans(ar.size(), 1);

       for(int i=1; i<ar.size(); i++){
        ans[i]=ar[i-1]*ans[i-1];
       }
        int suf = 1;
       for(int i=ar.size()-1; i>=0; i--){
        ans[i]*=suf;
        suf*=ar[i];
       }

        
        return ans;
    }
};