class Solution {
public:

    void backtrack(vector<string>& result, string curr, int n, int open, int close){
        if(curr.length() == 2 * n){
            result.push_back(curr);
            return;
        }

        if(open < n) {
            curr.push_back('(');
            backtrack(result, curr, n, open + 1, close);
            curr.pop_back();
        }

        // Add ')' only if there is an unmatched '('
        if(close < open) {
            curr.push_back(')');
            backtrack(result, curr, n, open, close + 1);
            curr.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        
        backtrack(result, curr, n,  0, 0);

        return result;
    }
};
// similar to pick  / don't pick pattern, but uses open and close to keep
// the paranthesis well formed