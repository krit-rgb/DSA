class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans = 0;
        stack<int> st;
        vector<int> ri(h.size(), 0);
        for(int i=h.size()-1; i>=0; i--){
            while(st.size()>0 && h[i]<=h[st.top()]){
                st.pop();
            }
            ri[i] = st.empty()?h.size():st.top();
            st.push(i);
        }

        stack<int> s;
        vector<int> le(h.size(), 0);
        for(int i=0; i<h.size(); i++){
            while(s.size()>0 && h[i]<=h[s.top()]){
                s.pop();
            }
            le[i] = s.empty()?-1:s.top();
            s.push(i);
        }
        for(int i=0; i<h.size(); i++){
            int hei = h[i];
            int w = ri[i] - le[i] -1;
            int currarea = hei*w;               //for the ith bar, curr area would be 
            ans = max(ans, currarea);
        }

        return ans;
    }
};