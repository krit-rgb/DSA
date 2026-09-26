class Solution {
public:
    vector<int> productExceptSelf(vector<int>& ar) {
        vector<int> pre(ar.size(), 1);
        for(int i=1; i<ar.size(); i++){
            pre[i]=pre[i-1]*ar[i-1];
        }   

        vector<int> suf(ar.size(), 1);
        for(int i=ar.size()-2; i>=0; i--){
            suf[i] = suf[i+1]*ar[i+1];
        }

        vector<int> ans(ar.size());
        for(int i=0; i<ar.size(); i++){
            ans[i]=pre[i]*suf[i];
        }

        return ans;
    }
};