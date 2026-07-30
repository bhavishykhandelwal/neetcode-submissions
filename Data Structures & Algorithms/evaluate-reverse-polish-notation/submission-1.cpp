class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            string ch=tokens[i];
            if(ch!="+" && ch!="-" && ch!="*" && ch!="/"){
                st.push(stoi(ch));
            }
            else{
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();

                if(ch=="+"){
                    st.push(num2+num1);
                }
                else if(ch=="-"){
                    st.push(num2-num1);
                }
                else if(ch=="*"){
                    st.push(num2*num1);
                }
                else{
                    st.push(num2/num1);
                }
            }
        }
        return st.top();
    }
};
