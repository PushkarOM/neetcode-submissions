class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
            
        // fixed size window
        
        vector<int> freqs1(26,0);

        vector<int> window_(26,0);

        int i = 0;  
        int k = s1.length();

        while(i < k){
            freqs1[s1[i] - 'a']++;
            i++;
        }

        i = 0;
        // s1 length window in s2
        while(i < k){
            window_[s2[i] - 'a']++;
            i++;
        } 

        if(window_ == freqs1){
            return true;
        }

        while(i < s2.length()){
            window_[s2[i] - 'a']++;
            window_[s2[i-k] - 'a']--;

            if(window_ == freqs1){
                return true;
            }

            i++;

        }

        return false;
    }
};
