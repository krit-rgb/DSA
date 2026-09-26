class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& ar, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<ar.size(); i++){
            if(m.find(ar[i])==m.end()){
                m[ar[i]] = i;
            }
            else{
                if(abs(i-m[ar[i]]) <= k){
                    return true;
                }
                else{
                    m[ar[i]] = i;
                }
            }
        }
        return false;
    }
};