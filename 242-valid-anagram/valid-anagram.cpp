class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> m;
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i])==m.end()){
                m[s[i]] = 1;

            }
            else{
                m[s[i]]++;
            }
        }
        for(int i=0; i<t.size(); i++){
            if(m.find(t[i])==m.end() || m[t[i]] == 0){
                return false;
            }
            m[t[i]]--;
        }
        return true;
    }
};