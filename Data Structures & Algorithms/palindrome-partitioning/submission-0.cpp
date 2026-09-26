class Solution {
public:
    vector<vector<string>> ans;
    vector<string> current;

    bool isPalindrome(string& s, int l, int r) {
        
        int left = l, right = r;

        while(left <= right){
            if(s[left] != s[right]) return false;

            left++;
            right--;
        }

        return true;
    }

    void backtrack(string& s, int start) {
        if(start == s.size()){
            ans.push_back(current);
            return;
        }

        // try every possible ending position
        for (int end = start; end < s.size(); end++) {
            if(isPalindrome(s,start,end)){

                current.push_back(s.substr(start, end-start+1));
                
                backtrack(s, end+1);

                current.pop_back();

            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return ans;
    }
};