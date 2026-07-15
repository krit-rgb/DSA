class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int se = 0;
        for(int i=1; i<=n; i++){
            se+=(2*i);
        }

        int so = 0;
        for(int i=1; i<=n; i++){
            so+=(2*i-1);
        }

        while(so!=0){
            int temp = so;
            so=se%so;
            se=temp;
        }

        return se;
    }
};