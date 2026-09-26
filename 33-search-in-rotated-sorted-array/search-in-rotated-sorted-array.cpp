class Solution {
public:
    int search(vector<int>& ar, int target) {
        int n=ar.size();
        int st=0, end=n-1, mid;

        while(st<=end){
            mid = (st+end)/2;
            if(ar[mid]==target) return mid;
            else if(ar[st]<=ar[mid]){          //left sorted
                if(target<=ar[mid] && ar[st]<=target){    //present in left
                    end=mid-1;
                }
                else{               //absent in left
                    st=mid+1;
                }
            }           

            else{       //right sorted
                if(target>=ar[mid] && ar[end]>=target){
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