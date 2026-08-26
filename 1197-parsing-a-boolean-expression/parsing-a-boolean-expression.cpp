class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(char ch : expression){
            if(ch == ','){
                continue;
            }
            if(ch != ')'){
                st.push(ch);
            }
            else{
                vector<char> values;
                while(st.top() != '('){
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                if(op == '!'){
                    st.push(values[0] == 't' ? 'f' : 't');
                }
                else if(op == '&'){
                    bool res = true;
                    for(char v : values){
                        if(v == 'f'){
                            res = false;
                            break;
                        }
                    }
                    st.push(res ? 't' : 'f');
                }
                else if(op == '|'){
                    bool res = false;
                    for(char v : values){
                        if(v == 't'){
                            res = true;
                            break;
                        }
                    }
                    st.push(res ? 't' : 'f');
                }
            }
        }
        return st.top() == 't';
    }
};