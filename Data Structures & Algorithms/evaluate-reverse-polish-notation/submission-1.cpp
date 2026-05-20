class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        for(auto it : tokens)
        {
            if(it == "+" || it == "-" || it == "*" || it == "/")
            {
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                if(it == "+")
                {
                    st.push(to_string(a+b));
                }
                if(it == "-")
                {
                    st.push(to_string(b-a));
                }
                if(it == "*")
                {
                    st.push(to_string(a*b));
                }
                if(it == "/")
                {
                    st.push(to_string(b/a));
                }
            }
            else
            {
                st.push(it);
            }
        }
        return stoi(st.top());
    }
};
