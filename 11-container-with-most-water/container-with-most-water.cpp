class Solution {
public:
    int maxArea(vector<int>& h) {
        int left = 0;
        int right = h.size()-1;
        
        int maxarea = INT_MIN;
        while(left<right){
            int width = right - left;
            int height = min(h[left], h[right]);
            int area = width*height;
            maxarea = max(maxarea, area);
            h[left]>h[right]?right--:left++;
        }

        return maxarea;
    }
};