class Solution {
public:
    int threeSumClosest(vector<int>& ar, int t) {
        sort(ar.begin(), ar.end());
        int ans;

        for(int i=0; i<ar.size(); i++){
            int j=i+1; 
            int k = ar.size()-1;
            while(j<k){
                int sum = ar[i]+ar[j]+ar[k];
                if(abs(t-sum) < abs(ans-t)) ans = sum;
                if(sum>t) k--;
                else if(sum<t) j++;
                else return sum;
            }
        }

        return ans;
    }
};