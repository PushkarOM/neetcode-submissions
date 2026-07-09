class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;

        for(auto it : tokens){
            
            if(isdigit(it[0]) || (it[0] == '-' && it.size() > 1)){
                st.push(stoi(it));
            }
            else{
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                if(it[0] == '+'){
                    st.push(temp1 + temp2);
                }
                else if(it[0] == '-'){
                    st.push(temp2 - temp1);
                }
                else if(it[0] == '*'){
                    st.push(temp1 * temp2);
                }
                else if(it[0] == '/'){
                    st.push(temp2 / temp1);
                }
            }
        }

        return st.top();
    }
};
