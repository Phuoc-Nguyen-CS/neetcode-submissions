class Solution {
public:
    bool isValid(string s) {

        std::stack<char> st;

        // If the top of the stack matches its corresponding parentheses we can pop
        for (char c : s) {
        
            if (c == '[' || c == '(' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false; // closer no opener

                char top = st.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                        st.pop();
                } else {
                    return false;
                }
            }
        }

        if (st.empty()) {
            return true;
        }

        return false;
    }
};
