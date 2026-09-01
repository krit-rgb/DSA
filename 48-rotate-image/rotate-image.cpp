class Solution {
public:
    void rotate(vector<vector<int>>& m) {
            for(int i=0; i<m.size(); i++){
                for(int j=i+1; j<m.size(); j++){
                    if(j>i) swap(m[i][j], m[j][i]);

                    
                }
                int l=0, r=m.size()-1;
                    while(l<r){
                        swap(m[i][l], m[i][r]);
                        l++; r--;
                    }
            }      

        
    }
};