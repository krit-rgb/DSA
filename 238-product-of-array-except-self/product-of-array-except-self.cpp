class Solution {
public:
    vector<int> productExceptSelf(vector<int>& ar) {
        vector<int> prod(ar.size(), 1);
        for(int i=1; i<ar.size(); i++){
            prod[i] = ar[i-1]*prod[i-1];
        }

        int suf = 1;
        for(int i=ar.size()-1; i>=0; i--){
            prod[i]*=suf;
            suf*=ar[i];
        }

        return prod;
    }
};