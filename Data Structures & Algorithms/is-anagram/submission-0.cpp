class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freqCountS(26,0);
        
        if(s.length() < t.length()) return false;


        for(int i = 0; i < s.length(); i++){
            freqCountS[abs('a' - s[i])]++;
        }

        for(int i = 0; i < t.length(); i++){
            freqCountS[abs('a' - t[i])]--;
        }

        for(auto it : freqCountS){
            if(it > 0){
                return false;
            }
        }
        return true;
    }
};