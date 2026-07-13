class Solution {
public:
    int search(vector<int>& ar, int t) {
        int st = 0, end = ar.size()-1, mid;

        while(st<=end){
            int mid = (st+end)/2;
            if(ar[mid]==t) return mid;
            else if(ar[mid]>=ar[st]){  //left sorted
                if(ar[st]<=t && ar[mid]>=t){ //target present
                    end=mid-1;
                }
                else{                       //not there
                    st=mid+1;
                }
            }
            else{                 //right sorted
                if(ar[mid]<=t && t<=ar[end]){
                    st=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};