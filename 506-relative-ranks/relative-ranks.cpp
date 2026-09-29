class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& s) {
        vector<string> ans(s.size());
        vector<pair<int, int>> v;
        for(int i=0; i<s.size(); i++){
             v.push_back({s[i],i});
        }

        sort(v.rbegin(), v.rend());

        for(int i=0; i<s.size(); i++){
            if(i==0){
                ans[v[i].second]="Gold Medal";
            }
            else if(i==1){
                ans[v[i].second]="Silver Medal";
            }
            else if(i==2){
                ans[v[i].second]="Bronze Medal";
            }
            else{
                ans[v[i].second] = to_string(i + 1);
            }
        }

        return ans;
    }
};