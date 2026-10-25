class Solution {
public:
    bool checkValidString(string s) {
        // 2 stacks 1 to keep track of left parenthesis and 1 to keep track of stars
        stack<char> leftPar, star;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') leftPar.push(i);
            else if(s[i] == '*') star.push(i);
            else{
                if(!leftPar.empty()) leftPar.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }

        while(!leftPar.empty() && !star.empty()){
            int x = leftPar.top(); leftPar.pop();
            int y = star.top(); star.pop();

            if(x > y) return false;
        }

        return leftPar.empty() ? true : false;
    }
};
