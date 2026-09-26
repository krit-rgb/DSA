class Solution {
public:
    int searchInsert(vector<int>& ar, int target) {
        int st=0, end=ar.size()-1, mid;
        while(st<=end){
            int mid = (st+end)/2;
            if(ar[mid]==target){
                return mid;
            }
            else if(ar[mid]>target){
                end=mid-1;
            }
            else{
                st=mid+1;
            }

            
        }
        return st;
    }
};