void insert(stack<int> &st,int temp){
    if((temp>st.top()&&!st.empty())||st.empty()){
        st.push(temp);
        return;
    }
    int val=st.top();
    st.pop();
    insert(st,val);
    st.push(val);
}
void sortStack(stack<int> &st)
{
    if(st.empty()) return;
    int temp=st.top();
    st.pop();
    sortStack(st);
    insert(st,temp);
    return;
}
