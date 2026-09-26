class Solution {
public:
    vector<int> productExceptSelf(vector<int>& ar) {
        vector<int> pre(ar.size(), 1);
        for(int i=1; i<ar.size(); i++){
            pre[i]=pre[i-1]*ar[i-1];
        }   

        int suf = 1;
        for(int i=ar.size()-1; i>=0; i--){
            pre[i] *= suf;
            suf *= ar[i];
        }

        

        return pre;
    }
};