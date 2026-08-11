class Solution {
public:
    int totalFruit(vector<int>& ar) {
        unordered_map<int, int> m;
        int left =0;
 int ans =0;
        for(int i=0; i<ar.size(); i++){
            if(m.find(ar[i]) == m.end()){
                m[ar[i]] = 1;
            }
            else{
                m[ar[i]]++;
            }
            while(m.size()>2){
                m[ar[left]]-=1;
                if(m[ar[left]] == 0){
                    m.erase(ar[left]);
                }
                left++;
            }
            ans = max(ans, i-left+1);
        }

        return ans;


    }
};